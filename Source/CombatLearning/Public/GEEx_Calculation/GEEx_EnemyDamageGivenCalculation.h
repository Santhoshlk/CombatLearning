// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEEx_EnemyDamageGivenCalculation.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UGEEx_EnemyDamageGivenCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UGEEx_EnemyDamageGivenCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
