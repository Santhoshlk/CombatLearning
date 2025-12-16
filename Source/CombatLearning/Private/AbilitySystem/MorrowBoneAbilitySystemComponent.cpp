// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"

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
