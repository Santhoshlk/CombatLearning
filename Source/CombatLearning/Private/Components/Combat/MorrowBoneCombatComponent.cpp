// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/MorrowBoneCombatComponent.h"
#include "Weapon/WeaponMorrowBone.h"

AWeaponMorrowBone* UMorrowBoneCombatComponent::GetMorrowBoneWeaponCarriedByTag(FGameplayTag InInputTag) const
{
	return Cast<AWeaponMorrowBone>(GetWeaponCarriedbyTag(InInputTag));
}
