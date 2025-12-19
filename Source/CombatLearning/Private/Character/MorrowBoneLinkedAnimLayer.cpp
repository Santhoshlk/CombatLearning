// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MorrowBoneLinkedAnimLayer.h"
#include "Character/Hero/MorrowBoneHeroAnimInstance.h"

UMorrowBoneHeroAnimInstance* UMorrowBoneLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UMorrowBoneHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
