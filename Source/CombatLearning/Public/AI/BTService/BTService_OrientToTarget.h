// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_OrientToTarget.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UBTService_OrientToTarget : public UBTService
{
	GENERATED_BODY()

	UBTService_OrientToTarget();

	// u also need to derive some functions to make this work
	//1) to describe the static description.
	//2)to initialize the Black Board Key it takes as an input

	
	virtual FString GetStaticDescription() const override;
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

	UPROPERTY(EditAnywhere, Category="InTargetKey")
	FBlackboardKeySelector InTargetKey;

	UPROPERTY(EditAnywhere, Category="RotationInterpSpeed")
	float RotationInterpSpeed;
	
};
