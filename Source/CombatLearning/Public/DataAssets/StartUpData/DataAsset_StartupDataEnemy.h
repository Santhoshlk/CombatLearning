// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartupData.h"
#include "DataAsset_StartupDataEnemy.generated.h"

class UEnemyGameplayAbility;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UDataAsset_StartupDataEnemy : public UDataAsset_StartupData
{
	GENERATED_BODY()
public:
 virtual void GiveToASC(TObjectPtr<UMorrowBoneAbilitySystemComponent>& ASC, int32 ApplyLevel = 1) override;
	
protected:
	UPROPERTY(EditDefaultsOnly,Category="StartupData|EnemyGameplayAbilities")
	TArray<TSubclassOf<UEnemyGameplayAbility>> EnemyGameplayAbilities;
};
