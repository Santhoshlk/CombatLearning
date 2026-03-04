// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RotateOrientToTarget.generated.h"

/**
 * 
 */
struct FOnMemoryRotateOrientToTarget
{
    //	Structs default access is public 
	// a place to store pointers that just required until not null
	TWeakObjectPtr<APawn> OwningPawn;
	TWeakObjectPtr<AActor> TargetActor;
	bool isValid()
	{
		return OwningPawn.IsValid() && TargetActor.IsValid();
	}
   void Reset()
	{
		OwningPawn = nullptr;
		TargetActor = nullptr;
	}
	
};


UCLASS()
class COMBATLEARNING_API UBTTask_RotateOrientToTarget : public UBTTaskNode
{
	GENERATED_BODY()

	UBTTask_RotateOrientToTarget();

	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

	/** size of instance memory */
	virtual uint16 GetInstanceMemorySize() const override;

	//**execute task**//
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	virtual FString GetStaticDescription() const override;
 
     bool IsInAnglePrecision(const APawn* QueryPawn, const AActor* TargetActor) const;	
	
	// u need some values
	UPROPERTY(EditAnywhere,Category = "Rotate Orient To Target")
	float AnglePrecision;

	UPROPERTY(EditAnywhere,Category = "Rotate Orient To Target")
	FBlackboardKeySelector InTargetKey;

	UPROPERTY(EditAnywhere,Category = "Rotate Orient To Target")
	float RotationInterpSpeed;
};
