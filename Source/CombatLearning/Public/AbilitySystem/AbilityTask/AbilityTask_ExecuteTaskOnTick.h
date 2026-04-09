// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_ExecuteTaskOnTick.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTickTaskDelegate,float, time);


/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UAbilityTask_ExecuteTaskOnTick : public UAbilityTask
{
	GENERATED_BODY()

public:

  // Create the delegate variable
  UPROPERTY(BlueprintAssignable)
	FOnTickTaskDelegate TickTaskDelegate;
	
	UAbilityTask_ExecuteTaskOnTick();

	

	// Generate the Static function which Calls the Ability Task
	UFUNCTION(BlueprintCallable,Category = "Ability Task ",meta=(HidePin = "OwningGameplayAbility",DisplayName = "ExecuteTaskOnTick",DefaultToSelf = "OwningGameplayAbility",BlueprintInternalUseOnly = "true"))
	static UAbilityTask_ExecuteTaskOnTick* ExecuteTaskOnTick(UGameplayAbility* OwningGameplayAbility);

	/** Tick function for this task, if bTickingTask == true */
	virtual void TickTask(float DeltaTime) override;	
};
