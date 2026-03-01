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
	UFUNCTION(BlueprintPure,Category="EnemyGameplayAbilty|Enemy")
	AEnemyBase* GetEnemyCharacter();

	UFUNCTION(BlueprintPure,Category="EnemyGameplayAbilty|Enemy")
	UEnemyCombatComponent* GetEnemyCombatComponentFromEnemy() ;

	UFUNCTION(BlueprintPure, Category= "EnemyGameplayAbilty|EffectSpecHandle")
	FGameplayEffectSpecHandle MakeMorrowBoneDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass,float level,float WeaponDamage);

private:
	TWeakObjectPtr<AEnemyBase> CachedEnemy;
};
