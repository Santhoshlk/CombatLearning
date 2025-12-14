// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataAssets/StartUpData/DataAsset_StartupData.h"
#include "DataAsset_StartupDataMorrowBone.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FMorrowBoneAbilitySet
{
	GENERATED_BODY()

	//we need a place to store our gameplay abilities to give to our hero not on given and have tags
	// so we create a new struct as these are not the same abilities in the base class startup_data
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(Category="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UMorrowBoneGameplayAbility> HeroInputGameplayAbility;

	bool IsValid();
};
UCLASS()
class COMBATLEARNING_API UDataAsset_StartupDataMorrowBone : public UDataAsset_StartupData
{
	GENERATED_BODY()
public:
	virtual void GiveToASC(TObjectPtr<UMorrowBoneAbilitySystemComponent> & ASC,int32 ApplyLevel=1) override;

   // this u to search by input Tags
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,meta=(TitleProperty="InputTag"))
	TArray<FMorrowBoneAbilitySet> HeroGameplayAbilities;
};
