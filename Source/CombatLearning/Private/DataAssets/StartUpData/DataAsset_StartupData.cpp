// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartupData.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"

void UDataAsset_StartupData::GiveToASC(TObjectPtr<UMorrowBoneAbilitySystemComponent>& ASC, int32 ApplyLevel)
{
	//it is important to check your ASC
	checkf(ASC,TEXT("The AbilitySystem Component is Not Valid for the Avatar Actor u want to give the Ability "));
	GrantAbility(CommonStartupAbility,ASC);
	GrantAbility(ReactiveAbility,ASC);
}

void UDataAsset_StartupData::GrantAbility(TArray<TSubclassOf<UMorrowBoneGameplayAbility>> &InitialAbilities,
	TObjectPtr<UMorrowBoneAbilitySystemComponent>& ASC, int32 ApplyLevel)
{
	if (InitialAbilities.IsEmpty())
	{
		return;
	}
	//Now Loop through the Data and Give THe Ability To your ASC
	for (const TSubclassOf<UMorrowBoneGameplayAbility>& Ability : InitialAbilities)
	{
		//always do the safety check
		if (!IsValid(Ability))
		{
			continue;
		}
		// The Function to register an Ability to your ASC
		FGameplayAbilitySpec AbilityToGive(Ability);
		AbilityToGive.Level=ApplyLevel;
		AbilityToGive.SourceObject=ASC->GetAvatarActor();
		ASC->GiveAbility(AbilityToGive);
	}

}
