// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interface/PawnCombatInterface.h"
#include "MorrowBoneClassBase.generated.h"

class UDataAsset_StartupData;
class UMorrowBoneAttributeSet;
class UMorrowBoneAbilitySystemComponent;

UCLASS()
class COMBATLEARNING_API AMorrowBoneClassBase : public ACharacter , public IAbilitySystemInterface , public IPawnCombatInterface
{
	GENERATED_BODY()

public:
	
	AMorrowBoneClassBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

      virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
protected:
	// the process is normal as we create the AbilitySystem components ,Attribute set which are common for both character and etc
     UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AblilitySystem")
	TObjectPtr<UMorrowBoneAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AttributeSet")
	TObjectPtr<UMorrowBoneAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly,Category="StartupData")
	TSoftObjectPtr<UDataAsset_StartupData> StartUpData;

	//to make this work we need to override
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

public:
    //make the public getters
	
	FORCEINLINE UMorrowBoneAbilitySystemComponent* GetMorrowBoneAbilitySystemComponent() const 
	{
		return AbilitySystemComponent.Get();
	}
    
	FORCEINLINE UMorrowBoneAttributeSet*  GetAttributeSet() const 
	{
		return AttributeSet.Get();
	}
};
