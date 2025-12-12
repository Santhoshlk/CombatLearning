// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "InputConfig_DataAsset.generated.h"

/**
 * 
 */
class UInputAction;
class UInputMappingContext;
// we are going to create an USTRUCT to have The GamePlay Tags
USTRUCT(BlueprintType)
struct FMorrowBoneInputMappingConfig
{
	GENERATED_BODY()

	//Now We can Add the Variables For Mapping Context Generally Input Action
	//Here it is GameplayTags
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(Category="InputTag"))
	FGameplayTag InputTag;

	//now u can declare The Input Action
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction;

	bool IsValid() const
	{
		return InputTag.IsValid() &&  InputAction!=nullptr;
	}
	
};
UCLASS()
class COMBATLEARNING_API UInputConfig_DataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	//what we are trying to do is Completely Separate
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	 TObjectPtr<UInputMappingContext> InputMappingContext;

	//create a TArray of the Struct
	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(TitleProperty="InputAction"))
	TArray<FMorrowBoneInputMappingConfig> NativeInputActions;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,meta=(TitleProperty="InputAction"))
	TArray<FMorrowBoneInputMappingConfig> AbilityInputActions;

	//create a function which goes through the Gameplay Tag and gives U correct One
	UInputAction* FindInputActionInGameplayTag(const FGameplayTag& InInputTag);
};
