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
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_HitPause)

	//**Tags for Shared Events **//
	
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Attack_MeeleAttack)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_SetByCaller_BaseDamage)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_HitReact_LightAttack)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_HitReact_HeavyAttack)

	//**Tags for Abilities Itself**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Weapon_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_UnEquip_Weapon_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_LightAttack_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_HeavyAttack_Axe)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackTypes_LightAttack)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackTypes_HeavyAttack)

	//**Tags For Shared Abilities **//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact_LightAttack)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact_HeavyAttack)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_HitPause)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_Death)

	//**Tags for Enemy Gameplay Abilities **//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Melee)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Ranged)

	
	//** Tags for state Machines || Status **//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_State_JumpToFinisher_Axe)
	 COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_State_Invulnerability)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_state_Straffing)
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Death)
	
	//** Tags for Enemy Weapon**//
	COMBATLEARNING_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon_SpikedBat)
}
