// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MorrowBoneBaseAnimInstance.h"
#include "MorrowBoneFunctionLibrary.h"

bool UMorrowBoneBaseAnimInstance::DoesOurPawnHaveTag(const FGameplayTag InInputTag) const
{
	if (APawn* OwningPawn  = TryGetPawnOwner())
	{
		return UMorrowBoneFunctionLibrary::NativeDoesActorHaveTag(OwningPawn,InInputTag);
	}
	return false;
}
