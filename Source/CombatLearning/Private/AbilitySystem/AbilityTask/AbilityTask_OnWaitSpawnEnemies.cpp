// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AbilityTask/AbilityTask_OnWaitSpawnEnemies.h"

#include "AbilitySystemComponent.h"
#include "CombatDebugHelper.h"
#include "NavigationSystem.h"
#include "Character/Enemy/EnemyBase.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"

UAbilityTask_OnWaitSpawnEnemies* UAbilityTask_OnWaitSpawnEnemies::WaitSpawnEnemies(UGameplayAbility* OwningAbility,
                                                                                   TSoftClassPtr<AEnemyBase> EnemiesSpawnClass, FGameplayTag InputTag, int32 NumToSpawn, const FVector& SpawnOrigin,float RadiusToSpawn
)
{
	 UAbilityTask_OnWaitSpawnEnemies* AbilityTask =   NewAbilityTask<UAbilityTask_OnWaitSpawnEnemies>(OwningAbility);

	// Set the Values Here
   AbilityTask->CachedEnemiesSpawnClass = EnemiesSpawnClass;
	AbilityTask->CachedTag = InputTag;
	AbilityTask->CachedNumToSpawn = NumToSpawn;
	AbilityTask->CachedSpawnOrigin = SpawnOrigin;
	AbilityTask->CachedRadiusToSpawn = RadiusToSpawn;
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
   if (CachedEnemiesSpawnClass.IsNull())
   {
   	// just send an Empty array and end the task
   	if (ShouldBroadcastAbilityTaskDelegates())
   	{
   		NotSpawnedEnemies.Broadcast(TArray<AEnemyBase*>());
   	}
   	EndTask();
   	 return;
   }
	
   //Now we do async loading of enemies
	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
	CachedEnemiesSpawnClass.ToSoftObjectPath(),
    FStreamableDelegate::CreateUObject(this,&UAbilityTask_OnWaitSpawnEnemies::OnEnemyAsyncLoad)
		);
}

void UAbilityTask_OnWaitSpawnEnemies::OnEnemyAsyncLoad()
{
  // Now we can get the loaded class
	UClass* LoadedClass = CachedEnemiesSpawnClass.Get();
   UWorld* LoadedWorld = 	GetWorld();

	if (LoadedClass && LoadedWorld)
	{
		// now do the actual spawning
		TArray<TObjectPtr<AEnemyBase>> SpawnedEnemies;
		for (int i=0;i<CachedNumToSpawn;i++)
		{
			FVector RandomLocation;
		  UNavigationSystemV1::K2_GetRandomLocationInNavigableRadius(LoadedWorld,CachedSpawnOrigin,RandomLocation,CachedRadiusToSpawn);
        // Now add z value to it
			RandomLocation+= FVector(0.f,0.f,150.f);

			FActorSpawnParameters Parameters;
			Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			//U have the Access to ASC of the GameplayAbility that uses it
		 const FRotator SpawnRotation = AbilitySystemComponent->GetAvatarActor()->GetActorForwardVector().ToOrientationRotator();
		
		AEnemyBase* SpawnedEnemy = 	LoadedWorld->SpawnActor<AEnemyBase>(LoadedClass,RandomLocation,SpawnRotation,Parameters);
			SpawnedEnemy->SetActorRotation(SpawnRotation);
		
			if (SpawnedEnemy)
			{
				SpawnedEnemies.Add(SpawnedEnemy);
			}
			
		}

		if (SpawnedEnemies.IsEmpty())
		{
			if (ShouldBroadcastAbilityTaskDelegates())
			{
				NotSpawnedEnemies.Broadcast(TArray<AEnemyBase*>());
			}
			EndTask();
		}
		else
		{
			if (ShouldBroadcastAbilityTaskDelegates())
			{
				OnEnemiesSpawnFinished.Broadcast(SpawnedEnemies);
			}
			EndTask();
		}
	}
	else
	{
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			NotSpawnedEnemies.Broadcast(TArray<AEnemyBase*>());
		}
		EndTask();
	}
	
}
