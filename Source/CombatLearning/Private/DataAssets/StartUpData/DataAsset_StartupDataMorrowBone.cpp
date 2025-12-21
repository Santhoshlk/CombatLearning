// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartupDataMorrowBone.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"

void UDataAsset_StartupDataMorrowBone::GiveToASC(TObjectPtr<UMorrowBoneAbilitySystemComponent>& ASC, int32 ApplyLevel)
{
	Super::GiveToASC(ASC, ApplyLevel);
	//as this Function consists of ASC we can give our abilities to ASC with Input Tags
	// Always Remember we need To give Abilities However What To our ASC
	for ( auto& InputGameplayAbilities :HeroGameplayAbilities)
	{
		if (!InputGameplayAbilities.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(InputGameplayAbilities.HeroInputGameplayAbility);
		// We have to set some things in here
		AbilitySpec.SourceObject=ASC->GetAvatarActor();
		AbilitySpec.Level=ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(InputGameplayAbilities.InputTag);
		ASC->GiveAbility(AbilitySpec);
	}
	
}
