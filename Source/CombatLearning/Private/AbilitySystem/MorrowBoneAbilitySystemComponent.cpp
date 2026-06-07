// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"

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
      if (InInputTag.MatchesTag(MorrowBoneGameplayTags::InputTag_ToggleAbility))
      {
	      // toggling as try to activate ability is an infinite loop
      	   if (!AbilitySpec.IsActive())
      	   {
	      	   TryActivateAbility(AbilitySpec.Handle);
      	   }
           else
           {
           	   CancelAbilityHandle(AbilitySpec.Handle);
           }
      }
      else
      {
      	TryActivateAbility(AbilitySpec.Handle);
      }
		
	}
}

void UMorrowBoneAbilitySystemComponent::OnReleased(FGameplayTag InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}
	// // when to actually cancel the ability
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.IsActive()) continue;
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) continue;
		if (InInputTag.MatchesTag(MorrowBoneGameplayTags::InputTag_MustBeHeld))
		{
			CancelAbilityHandle(AbilitySpec.Handle);
		}
	}
}

void UMorrowBoneAbilitySystemComponent::GiveWeaponAbilitiestoASC(const 
	TArray<FMorrowBoneAbilitySet>& WeaponGameplayAbilities,const TArray<FMorrowBoneSpecialWeaponAbilitySet>& SpecialWeaponAbilities, int32 ApplyLevel,TArray<FGameplayAbilitySpecHandle>& OutGrantedSpecHandle)
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

	for (const auto& AbilitiesToGrant : SpecialWeaponAbilities)
	{
		if (!AbilitiesToGrant.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitiesToGrant.HeroInputGameplayAbility);

		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitiesToGrant.InputTag);

		// next give to asc
		GiveAbility(AbilitySpec);
	}
}

void UMorrowBoneAbilitySystemComponent::RemoveWeaponGameplayAbilities(
	TArray<FGameplayAbilitySpecHandle>& OutGrantedWeaponAbilitySpecHandle)
{
	 if (OutGrantedWeaponAbilitySpecHandle.IsEmpty())
	 {
		 return;
	 }
	for (const auto& WeaponAbilitiesToRemove : OutGrantedWeaponAbilitySpecHandle)
	{
		if (WeaponAbilitiesToRemove.IsValid())
		{
			ClearAbility(WeaponAbilitiesToRemove);
		}
	}
	OutGrantedWeaponAbilitySpecHandle.Empty();
}

bool UMorrowBoneAbilitySystemComponent::TryActivateEnemyGameplayAbilities(FGameplayTag EnemyAbilityTag)
{
	checkf(EnemyAbilityTag.IsValid(), TEXT("The GameplayTag is Not Valid"));

	// it gives out all the Matching GameplayAbilitySpec Pointers
	TArray<FGameplayAbilitySpec*> EnemyGameplayAbilitySpec;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(EnemyAbilityTag.GetSingleTagContainer(),EnemyGameplayAbilitySpec);

	if (!EnemyGameplayAbilitySpec.IsEmpty())
	{
		// u can activate the abilities
		int32 RandomIndex = FMath::RandRange(0,EnemyGameplayAbilitySpec.Num()-1);
		const FGameplayAbilitySpec* AbilityToActivate = EnemyGameplayAbilitySpec[RandomIndex];
		if (!AbilityToActivate->IsActive())
		{
			return TryActivateAbility(AbilityToActivate->Handle);
		}
	}
	return false;
}



