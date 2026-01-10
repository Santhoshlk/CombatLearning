// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Weapon/WeaponBase.h"
#include "Components/BoxComponent.h"


void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InInputTag, AWeaponBase* Weapon, bool IsEquipped)
{
	// u need to check both are valid before adding
	checkf(InInputTag.IsValid(),TEXT("The Tag which u are using to add the weapon is not valid "));
	checkf(IsValid(Weapon),TEXT("The Weapon which u are trying To register is not valid"));

	// To not add double have a return check
	// instead of check because of a common GAS quirk as it will call this func twice
	if (WeaponsToRegister.Contains(InInputTag))
	{
		return;
	}
	//now as we bind these we can use set the logic in func that can get called anywhere
	Weapon->WeaponHitTarget.BindUObject(this,&UPawnCombatComponent::OnWeaponHitTarget);
	Weapon->WeaponPulledFromTarget.BindUObject(this,&UPawnCombatComponent::OnWeaponPulledFromFromTarget);

	
	//else we can add
	WeaponsToRegister.Emplace(InInputTag,Weapon);

	if (IsEquipped)
	{
		CurrentWeaponTag=InInputTag;
	}
	// To show That This work we can add a debug Message

	
}

AWeaponBase* UPawnCombatComponent::GetWeaponCarriedbyTag(FGameplayTag InputTag) const
{
	// Just a case check
		if (!InputTag.IsValid())
		{
			return nullptr;
		}
	 if (AWeaponBase* const* SearchedWeapon=WeaponsToRegister.Find(InputTag))
	 {
	 	return *SearchedWeapon;
	 }
	return nullptr;
}

AWeaponBase* UPawnCombatComponent::GetEquippedWeapon() const
{
	if (!CurrentWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetWeaponCarriedbyTag(CurrentWeaponTag);
	
}

void UPawnCombatComponent::ToggleWeaponCollision(bool ActiveWeaponCollision, EWeaponEquippedTypes WeaponEquippedTypes)
{
	if (WeaponEquippedTypes==EWeaponEquippedTypes::CurrentWeaponEquipped)
	{
		AWeaponBase* WeaponEquipped=GetEquippedWeapon();

		checkf(WeaponEquipped,TEXT("The Weapon that u are equipping is not valid"));

		if (ActiveWeaponCollision)
		{
			WeaponEquipped->GetBoxCollision()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			
		}
		else
		{
			WeaponEquipped->GetBoxCollision()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			
		}
	}
}

void UPawnCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
	//we bound this to delegate which calls when any weapon has an overlap
	
}

void UPawnCombatComponent::OnWeaponPulledFromFromTarget(AActor* HitActor)
{
	//we bound this to delegate which calls when any weapon has an overlap
}


