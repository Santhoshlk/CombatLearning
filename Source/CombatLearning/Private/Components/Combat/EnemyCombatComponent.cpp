// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"

void UEnemyCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	FGameplayEventData Event;
	Event.Instigator = GetOwningPawn();
	Event.Target = HitActor;
	
	// now actually do the logic of sending gameplay event
	OverlappedActors.AddUnique(HitActor);
    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(),
    MorrowBoneGameplayTags::Shared_Attack_MeeleAttack,
    Event
    );
	
}
