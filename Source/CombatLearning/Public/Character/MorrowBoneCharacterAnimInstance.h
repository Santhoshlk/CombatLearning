// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneBaseAnimInstance.h"
#include "MorrowBoneCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class AMorrowBoneClassBase;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneCharacterAnimInstance : public UMorrowBoneBaseAnimInstance
{
	GENERATED_BODY()

public:
	//If u have doubt That UNeed To call Super Then Go and Check The Signature
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

#pragma region Components
	UPROPERTY()
	TObjectPtr<AMorrowBoneClassBase> OwningPtr;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwningCharacterMovement;
#pragma endregion

#pragma region Variables

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Speed")
	float GroundSpeed;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Acceleration")
	bool bHasAcceleration;
#pragma endregion
};
