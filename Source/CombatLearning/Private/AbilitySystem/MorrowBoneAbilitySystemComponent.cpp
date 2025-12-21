// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"

void UMorrowBoneAbilitySystemComponent::OnPressed(FGameplayTag InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}
	//we need to check if the tags have been activated or then wee need to activate them
	for (const auto& AbilitySpec :GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) continue;

		//next if it has the Tag
		// u Activate The Abilities
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UMorrowBoneAbilitySystemComponent::OnReleased(FGameplayTag InInputTag)
{
	
}

void UMorrowBoneAbilitySystemComponent::GiveWeaponAbilitiestoASC(const 
	TArray<FMorrowBoneAbilitySet>& WeaponGameplayAbilities, int32 ApplyLevel,TArray<FGameplayAbilitySpecHandle>& OutGrantedSpecHandle)
{
	if (WeaponGameplayAbilities.IsEmpty())
	{
		return;
	}

	for ( const auto& WeaponAbilitySet:WeaponGameplayAbilities)
	{
		if(!WeaponAbilitySet.IsValid())
		{
			continue;
		}

		FGameplayAbilitySpec AbilitySpec(WeaponAbilitySet.HeroInputGameplayAbility);
		//next setup the things
		AbilitySpec.SourceObject=GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(WeaponAbilitySet.InputTag);

		//give the ability and store the return value in Ability spec handle
		OutGrantedSpecHandle.AddUnique(GiveAbility(AbilitySpec));
	}
}



