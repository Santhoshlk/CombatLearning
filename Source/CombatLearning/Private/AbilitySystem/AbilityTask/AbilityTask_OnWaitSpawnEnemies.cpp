// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AbilityTask/AbilityTask_OnWaitSpawnEnemies.h"

#include "AbilitySystemComponent.h"
#include "CombatDebugHelper.h"

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

void UAbilityTask_OnWaitSpawnEnemies::Activate()
{
	// no need to call super here
	FGameplayEventMulticastDelegate& Delegate = AbilitySystemComponent->GenericGameplayEventCallbacks.FindOrAdd(CachedTag);
	DelegateHandle = Delegate.AddUObject(this,&UAbilityTask_OnWaitSpawnEnemies::OnGameplayEventTagReceived);
}

void UAbilityTask_OnWaitSpawnEnemies::OnDestroy(bool bInOwnerFinished)
{
	FGameplayEventMulticastDelegate& Delegate = AbilitySystemComponent->GenericGameplayEventCallbacks.FindOrAdd(CachedTag);
	Delegate.Remove(DelegateHandle);
	// super needs to be called last
	Super::OnDestroy(bInOwnerFinished);
}

void UAbilityTask_OnWaitSpawnEnemies::OnGameplayEventTagReceived(const FGameplayEventData* Data)
{
	Debug::PrintMessage("Gameplay Event Received");
	// Now that its done End Task
	EndTask();
}
