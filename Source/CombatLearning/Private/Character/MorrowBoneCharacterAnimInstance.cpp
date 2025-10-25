// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MorrowBoneCharacterAnimInstance.h"
#include "Character/MorrowBoneClassBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMorrowBoneCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwningPtr=Cast<AMorrowBoneClassBase>(TryGetPawnOwner());
	if (OwningPtr)
	{
		OwningCharacterMovement=OwningPtr->GetCharacterMovement();
	}
}

void UMorrowBoneCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	//check if Owning Ptr and Owning Character Movement is valid
	if (IsValid(OwningPtr) && OwningCharacterMovement )
	{
		GroundSpeed=OwningCharacterMovement->Velocity.Size2D();
		bHasAcceleration=OwningCharacterMovement->GetCurrentAcceleration().SizeSquared2D()>0.f;
	}
}

