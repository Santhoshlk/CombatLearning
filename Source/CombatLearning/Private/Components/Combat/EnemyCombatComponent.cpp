// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MorrowBoneFunctionLibrary.h"
#include "Character/Enemy/EnemyBase.h"
#include "Components/BoxComponent.h"
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

void UEnemyCombatComponent::ToggleBodyWeaponCollision(bool ActivateWeaponCollision, EWeaponEquippedTypes EquippedWeapon)
{
   // u need to get the Hit Boxes
	AEnemyBase* Enemy = Cast<AEnemyBase>(GetOwner());

	checkf(Enemy,TEXT("The Enemy which owns the Combat Component is not valid."))

	UBoxComponent* LeftCollisionBox = Enemy->GetLeftBoxCollision();
	UBoxComponent* RightCollisionBox = Enemy->GetRightBoxCollision();

	checkf(LeftCollisionBox && RightCollisionBox ,TEXT("The Collision Boxes which u are using are not valid."))
   switch (EquippedWeapon)
   {
	case EWeaponEquippedTypes::LeftHanded :
   	ActivateWeaponCollision ? LeftCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly) :  LeftCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
   	break;
   	
	case EWeaponEquippedTypes::RightHanded:
   	ActivateWeaponCollision ? RightCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly) :  RightCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
   	break;

	default:
   	break;
   }// Now for the Second Part Empty out the Array
	if (!ActivateWeaponCollision)
	{
		OverlappedActors.Empty();
	}
	
}
