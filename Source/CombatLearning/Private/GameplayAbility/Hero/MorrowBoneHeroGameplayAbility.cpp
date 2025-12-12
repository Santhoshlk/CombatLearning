// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Hero/MorrowBoneHeroGameplayAbility.h"
#include "Character/MorrowBone.h"
#include "PlayerController/CombatClassPlayerController.h"

AMorrowBone* UMorrowBoneHeroGameplayAbility::GetMorrowBoneCharacter()
{
	if (!CachedCharacter.IsValid())
	{
		CachedCharacter=Cast<AMorrowBone>(CurrentActorInfo->AvatarActor);
	}
	return CachedCharacter.Get();
}

ACombatClassPlayerController* UMorrowBoneHeroGameplayAbility::GetMorrowBonePlayerController()
{
	if (!CachedPlayerController.IsValid())
	{
		CachedPlayerController=Cast<ACombatClassPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedPlayerController.Get();
}

UMorrowBoneCombatComponent* UMorrowBoneHeroGameplayAbility::GetMorrowBoneCombatComponent()
{
	return GetMorrowBoneCharacter()->GetCombatComponent();
}
