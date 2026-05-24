// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AbilityTask/AbilityTask_OnWaitSpawnEnemies.h"

UAbilityTask_OnWaitSpawnEnemies* UAbilityTask_OnWaitSpawnEnemies::WaitSpawnEnemies(UGameplayAbility* OwningAbility,
	TSoftClassPtr<AEnemyBase> EnemiesSpawnClass, FGameplayTag InputTag, int32 NumToSpawn, const FVector& SpawnLocation,
	const FRotator& SpawnRotation)
{
	 UAbilityTask_OnWaitSpawnEnemies* AbilityTask =   NewAbilityTask<UAbilityTask_OnWaitSpawnEnemies>(OwningAbility);

	// Set the Values Here
   AbilityTask->CachedEnemiesSpawnClass = EnemiesSpawnClass;
	AbilityTask->CachedTag = InputTag;
	AbilityTask->CachedNumToSpawn = NumToSpawn;
	AbilityTask->CachedSpawnLocation = SpawnLocation;
	AbilityTask->CachedSpawnRotation = SpawnRotation;
	
	return AbilityTask;
}
