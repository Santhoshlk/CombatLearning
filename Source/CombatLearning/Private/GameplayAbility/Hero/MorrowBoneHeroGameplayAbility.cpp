// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Hero/MorrowBoneHeroGameplayAbility.h"

#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "Character/MorrowBone.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"
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

FGameplayEffectSpecHandle UMorrowBoneHeroGameplayAbility::MakeMorrowBoneDamageEffectSpecHandle(
	TSubclassOf<UGameplayEffect> EffectClass, float weaponBaseDamage, FGameplayTag CurrentAttackType,
	int32 UsedComboCount)
{
	//check the effect class
	checkf(EffectClass,TEXT("You must provide a valid effect class"));

	// create a Effect Context Handle
	FGameplayEffectContextHandle EffectContextHandle=GetMorrowBoneAbilitySystemComponent()->MakeEffectContext();
	//now set some properties in the effect context handle
	EffectContextHandle.SetAbility(this);
	EffectContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	EffectContextHandle.AddInstigator(GetAvatarActorFromActorInfo(),GetAvatarActorFromActorInfo());

	
	FGameplayEffectSpecHandle EffectSpecHandle= GetMorrowBoneAbilitySystemComponent()->MakeOutgoingSpec(
	EffectClass,
	GetAbilityLevel(),
	EffectContextHandle
	);

	// u have to set something's in the effect specHandle
	if (CurrentAttackType.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(CurrentAttackType,UsedComboCount);
	}

	EffectSpecHandle.Data->SetSetByCallerMagnitude(MorrowBoneGameplayTags::Shared_SetByCaller_BaseDamage,weaponBaseDamage);
	return EffectSpecHandle;
}

