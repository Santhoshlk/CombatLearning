// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

//** we are declaring gameplay tags for all our input actions and under the same namespace of project **//

namespace MorrowBoneGameplayTags
{
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Equip_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnEquip_Axe)

	//** Declare ur Tags**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe)
}
