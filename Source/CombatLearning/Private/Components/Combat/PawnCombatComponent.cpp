// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Weapon/WeaponBase.h"
#include "CombatDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapons(FGameplayTag InputRegisterTag, AWeaponBase* WeaponToRegister,
	bool IsWeaponEquipped) 
{
	//u also need to check that if the weapons registered contains the Tag already
	if (RegisteredWeapons.Contains(InputRegisterTag))
	{
		return;
	}
	check(InputRegisterTag.IsValid())
	checkf(IsValid(WeaponToRegister),TEXT("The Weapon Which u are Trying to Register is Invalid"));
	RegisteredWeapons.Emplace(InputRegisterTag,WeaponToRegister);
	if (IsWeaponEquipped)
	{
		CurrentEquippedWeaponTag=InputRegisterTag;
	}
	// if you're able to register then print a debug message
	FString Message=FString::Printf(TEXT("The Weapon Spawned is registered under Weapon:%s and GameplayTag:%s"),*WeaponToRegister->GetName(),*InputRegisterTag.ToString());
	Debug::PrintMessage(Message);
	
}

AWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InputTag)
{
	//u need to add another layering of * as we are using Const a good practice
	if (AWeaponBase* const* Weapon=RegisteredWeapons.Find(InputTag))
	{
		return *Weapon;
	}
	return nullptr;
}

AWeaponBase* UPawnCombatComponent::GetCharacterCurrentWeapon() const
{
	//if u don't have a current tag return nullptr
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	if (AWeaponBase* const* Weapon=RegisteredWeapons.Find(CurrentEquippedWeaponTag))
	{
		return *Weapon;
	}
	return nullptr;
}


