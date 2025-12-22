// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/MorrowBoneGameplayAbility.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"


void UMorrowBoneGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	//FGameplayAbilityActorInfo is a great struct which can have a lot of Info about our actor
	//i we want we acn include our ASC header and  get Some Functions
	if (ActivationPolicy==EMorrowBoneAbilityActivationPolicy::onGiven  && !Spec.IsActive())
	{
		//to Activate Ability
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
	}
	
}

void UMorrowBoneGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	if (ActivationPolicy==EMorrowBoneAbilityActivationPolicy::onGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UMorrowBoneAbilitySystemComponent* UMorrowBoneGameplayAbility::GetMorrowBoneAbilitySystemComponent() const
{
	return Cast<UMorrowBoneAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

