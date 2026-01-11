// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/MorrowBoneCombatComponent.h"
#include "Weapon/WeaponMorrowBone.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"

AWeaponMorrowBone* UMorrowBoneCombatComponent::GetMorrowBoneWeaponCarriedByTag(FGameplayTag InInputTag) const
{
	return Cast<AWeaponMorrowBone>(GetWeaponCarriedbyTag(InInputTag));
}

void UMorrowBoneCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
	Super::OnWeaponHitTarget(HitActor);
  // Now when we overlap and get an actor we can check and add it to the array , and we can send a gameplay event.
  //to give damage to APawn

	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	OverlappedActors.AddUnique(HitActor);

	//send a gameplay event to actor

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		MorrowBoneGameplayTags::Shared_Attack_LightAttack,
		 EventData
		);
}

void UMorrowBoneCombatComponent::OnWeaponPulledFromFromTarget(AActor* HitActor)
{
	Super::OnWeaponPulledFromFromTarget(HitActor);
	
}
