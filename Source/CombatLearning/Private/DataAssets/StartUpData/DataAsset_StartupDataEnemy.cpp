// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartupDataEnemy.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "GameplayAbility/EnemyGameplayAbility.h"

void UDataAsset_StartupDataEnemy::GiveToASC(TObjectPtr<UMorrowBoneAbilitySystemComponent>& ASC, int32 ApplyLevel)
{
	Super::GiveToASC(ASC, ApplyLevel);
	// now just give the abilities to ASC

	if (EnemyGameplayAbilities.IsEmpty())
	{
		return;
	}
	for (const auto& AbilitiesToGrant:EnemyGameplayAbilities)
	{
		if (!AbilitiesToGrant) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitiesToGrant);

		AbilitySpec.SourceObject=ASC->GetAvatarActor();
		AbilitySpec.Level=ApplyLevel;
		ASC->GiveAbility(AbilitySpec);
	}
}
