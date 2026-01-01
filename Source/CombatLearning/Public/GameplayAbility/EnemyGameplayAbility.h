// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"
#include "EnemyGameplayAbility.generated.h"

class UEnemyCombatComponent;
class AEnemyBase;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UEnemyGameplayAbility : public UMorrowBoneGameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure,Category="GameplayAbility|Enemy")
	AEnemyBase* GetEnemyCharacter();

	UFUNCTION(BlueprintPure,Category="GameplayAbility|Enemy")
	UEnemyCombatComponent* GetEnemyCombatComponent() const;

private:
	TWeakObjectPtr<AEnemyBase> CachedEnemy;
};
