// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_OnWaitSpawnEnemies.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaitSpawnEnemiesDelegate, const TArray<AEnemyBase*>&,SpawnedEnemies);

class AEnemyBase;
/**
 * 
 */


UCLASS()
class COMBATLEARNING_API UAbilityTask_OnWaitSpawnEnemies : public UAbilityTask
{
	GENERATED_BODY()

public:
	//Creation of Ability Task

	UFUNCTION(BlueprintCallable,meta=(DisplayName = "Wait Gameplay Event and Spawn Enemies",HidePin = "OwningAbility",DefaultToSelf = "OwningAbility",BlueprintInternalUseOnly = "true", NumToSpawn = "1",SpawnLocation = "200"))
	static UAbilityTask_OnWaitSpawnEnemies* WaitSpawnEnemies(UGameplayAbility* OwningAbility,
		TSoftClassPtr<AEnemyBase> EnemiesSpawnClass,
		FGameplayTag InputTag,
		int32 NumToSpawn ,
		const FVector& SpawnOrigin,
		float RadiusToSpawn,
		const FRotator& SpawnRotation
		);

	// Output Should be delegates
	UPROPERTY(BlueprintAssignable)
	FOnWaitSpawnEnemiesDelegate OnEnemiesSpawnFinished;

	UPROPERTY(BlueprintAssignable)
	FOnWaitSpawnEnemiesDelegate NotSpawnedEnemies;


private:
	// the data stored per use of this ability Task
	FGameplayTag CachedTag;
	TSoftClassPtr<AEnemyBase> CachedEnemiesSpawnClass;
	int32 CachedNumToSpawn;
	 FVector CachedSpawnOrigin;
	 FRotator CachedSpawnRotation;
   FDelegateHandle DelegateHandle;
	float CachedRadiusToSpawn;
	
	virtual void Activate() override;
	virtual void OnDestroy(bool bInOwnerFinished) override;


	void OnGameplayEventTagReceived( const FGameplayEventData* Data);

	void OnEnemyAsyncLoad();
};
