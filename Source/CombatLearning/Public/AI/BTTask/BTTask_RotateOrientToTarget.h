// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RotateOrientToTarget.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UBTTask_RotateOrientToTarget : public UBTTaskNode
{
	GENERATED_BODY()

	UBTTask_RotateOrientToTarget();

	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

	virtual FString GetStaticDescription() const override;
	
	// u need some values
	UPROPERTY(EditAnywhere,Category = "Rotate Orient To Target")
	float AnglePrecision;

	UPROPERTY(EditAnywhere,Category = "Rotate Orient To Target")
	FBlackboardKeySelector InTargetKey;

	UPROPERTY(EditAnywhere,Category = "Rotate Orient To Target")
	float RotationInterpSpeed;
};
