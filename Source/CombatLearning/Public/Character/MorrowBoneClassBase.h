// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MorrowBoneClassBase.generated.h"

class UMorrowBoneAttributeSet;
class UMorrowBoneAbilitySystemComponent;

UCLASS()
class COMBATLEARNING_API AMorrowBoneClassBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	AMorrowBoneClassBase();

protected:
	// the process is normal as we create the AbilitySystem components ,Attribute set which are common for both character and etc
     UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AblilitySystem")
	TObjectPtr<UMorrowBoneAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AttributeSet")
	TObjectPtr<UMorrowBoneAttributeSet> AttributeSet;

public:
    //make the public getters
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UMorrowBoneAbilitySystemComponent* GetAbilitySystemComponent() const 
	{
		return AbilitySystemComponent.Get();
	}
    UFUNCTION(BlueprintCallable)
	FORCEINLINE UMorrowBoneAttributeSet*  GetAttributeSet() const 
	{
		return AttributeSet.Get();
	}
};
