// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MorrowBoneFunctionLibrary.h"
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

	OverlappedActors.AddUnique(HitActor);

	bool bIsPlayerBlocking;
	bool bIsValidBlock = false;
	bool bIsUnBlockable = UMorrowBoneFunctionLibrary::NativeDoesActorHaveTag(GetOwningPawn(),MorrowBoneGameplayTags::Enemy_Attack_UnBlockable);
	

	// is player Blocking
	bIsPlayerBlocking = UMorrowBoneFunctionLibrary::BP_DoesActorHaveTag(HitActor,MorrowBoneGameplayTags::Player_Status_Block);

	if (bIsPlayerBlocking && !bIsUnBlockable)
	{
		  // now u can check if it is a valid block
		bIsValidBlock = UMorrowBoneFunctionLibrary::ValidBlock(GetOwningPawn(),HitActor);
	}

	if (bIsValidBlock)
	{
		// handle the successful block
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			HitActor,
			MorrowBoneGameplayTags::Player_Event_SuccessfulBlock,
			Event
			);
		
	}
	else
	{
		// non-successful block send gameplay event to enemy
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(),
		MorrowBoneGameplayTags::Shared_Attack_MeeleAttack,
		Event
		);
	}
	
	
}
