// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEEx_Calculation_DamageTaken.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UGEEx_Calculation_DamageTaken : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:
	UGEEx_Calculation_DamageTaken();

	//override  execute func to actually do the  capture of attributes
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
	
};
