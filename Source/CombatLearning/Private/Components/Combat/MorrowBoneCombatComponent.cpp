// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/MorrowBoneCombatComponent.h"
#include "Weapon/WeaponMorrowBone.h"

AWeaponMorrowBone* UMorrowBoneCombatComponent::GetMorrowBoneWeaponCarriedByTag(FGameplayTag InInputTag) const
{
	return Cast<AWeaponMorrowBone>(GetWeaponCarriedbyTag(InInputTag));
}

void UMorrowBoneCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
	Super::OnWeaponHitTarget(HitActor);

	if (GEngine && HitActor)
	{
		GEngine->AddOnScreenDebugMessage(0,2.f,FColor::MakeRandomColor(),TEXT("The Weapon Hit")+HitActor->GetActorNameOrLabel());
	}
}

void UMorrowBoneCombatComponent::OnWeaponPulledFromFromTarget(AActor* HitActor)
{
	Super::OnWeaponPulledFromFromTarget(HitActor);
	if (GEngine && HitActor)
	{
		GEngine->AddOnScreenDebugMessage(0,2.f,FColor::MakeRandomColor(),TEXT("The Weapon pulled from")+HitActor->GetActorNameOrLabel());
	}
}
