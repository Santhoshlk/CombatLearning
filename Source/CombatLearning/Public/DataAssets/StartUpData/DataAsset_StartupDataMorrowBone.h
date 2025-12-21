// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponStruct/WeaponStructTypes.h"
#include "DataAssets/StartUpData/DataAsset_StartupData.h"
#include "DataAsset_StartupDataMorrowBone.generated.h"

/**
 * 
 */


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
