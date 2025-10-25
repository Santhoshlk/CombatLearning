// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MorrowBoneCharacterAnimInstance.h"
#include "Character/MorrowBoneClassBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMorrowBoneCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwningPtr=Cast<AMorrowBoneClassBase>(TryGetPawnOwner());
	checkf(OwningPtr,TEXT("You were Not able To Successfully cast to the owning ptr"));
	OwningCharacterMovement=OwningPtr->GetCharacterMovement();
}

void UMorrowBoneCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	//check if Owning Ptr and Owning Character Movement is valid
	if (IsValid(OwningPtr) && OwningCharacterMovement  )
	{
		GroundSpeed=OwningCharacterMovement->Velocity.Size2D();
		bHasAcceleration=OwningCharacterMovement->GetCurrentAcceleration().SizeSquared2D()>0.f;
	}
}
