// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

//** we are declaring gameplay tags for all our input actions and under the same namespace of project **//

namespace MorrowBoneGameplayTags
{
	//**Tags For input action**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)

	//**Tags for ability Inputs**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Equip_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnEquip_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe)

	//** Tags for ur weapons**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe)

	//**Tags for notifies and events**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Weapon_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Weapon_Axe)

	//**Tags for Abilities Itself**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Weapon_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_UnEquip_Weapon_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_LightAttack_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_HeavyAttack_Axe)
}
