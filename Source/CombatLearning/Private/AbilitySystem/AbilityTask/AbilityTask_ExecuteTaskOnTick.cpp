// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AbilityTask/AbilityTask_ExecuteTaskOnTick.h"


UAbilityTask_ExecuteTaskOnTick::UAbilityTask_ExecuteTaskOnTick()
{
	bTickingTask = true;
}

UAbilityTask_ExecuteTaskOnTick* UAbilityTask_ExecuteTaskOnTick::ExecuteTaskOnTick(
	UGameplayAbility* OwningGameplayAbility)
{
	// Create the New Ability Task
	UAbilityTask_ExecuteTaskOnTick* TickTask = NewAbilityTask<UAbilityTask_ExecuteTaskOnTick>(OwningGameplayAbility);
	return TickTask;
}

void UAbilityTask_ExecuteTaskOnTick::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);
	// The output is the Broadcasted value
   if (ShouldBroadcastAbilityTaskDelegates())
   {
	   TickTaskDelegate.Broadcast(DeltaTime);
   }
   else
   {
	  // the ability is ended so the task also should be ended
   	   EndTask();
   }
	
}


