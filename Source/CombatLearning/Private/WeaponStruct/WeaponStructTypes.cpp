// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponStruct/WeaponStructTypes.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"

bool FMorrowBoneAbilitySet::IsValid() const
{
	return InputTag.IsValid() && HeroInputGameplayAbility!=nullptr;
}


