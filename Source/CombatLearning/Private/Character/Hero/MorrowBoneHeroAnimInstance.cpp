// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Hero/MorrowBoneHeroAnimInstance.h"

#include "Character/MorrowBone.h"

void UMorrowBoneHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	//we need a current reference to our actual ptr
	if (OwningPtr)
	{
		OwningPlayerCharacter=Cast<AMorrowBone>(OwningPtr);
		
	}
	
}

void UMorrowBoneHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaTime)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaTime);
	if (bHasAcceleration)
	{
		IdleElapsedTime=0.f;
		bShouldEnterRelaxedState=false;
	}
	else
	{
		IdleElapsedTime+=DeltaTime;
		bShouldEnterRelaxedState=(IdleElapsedTime>=EnterRelaxedStateThreshold);
	}
}
