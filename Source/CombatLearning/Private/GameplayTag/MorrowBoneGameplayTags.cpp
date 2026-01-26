// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTag/MorrowBoneGameplayTags.h"

//** now that we have declared the GameplayTags Under the Namespace Just Define Them using the same Unreal Definition**\\

namespace MorrowBoneGameplayTags
{
	// to define the game play tags u don't need the project name
	//adopt the dot system
	//Here the Tag name is the Literal Name you are going to see in the editor

	//**normal input tags**//
  UE_DEFINE_GAMEPLAY_TAG(InputTag_Move,TEXT("InputTag.Move"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look,TEXT("InputTag.Look"))

	//**ability input tags**//
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip_Axe,TEXT("InputTag.Equip.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquip_Axe,TEXT("InputTag.UnEquip.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe,TEXT("InputTag.LightAttack.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe,TEXT("InputTag.HeavyAttack.Axe"))

	//**weapon input tags**//
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,TEXT("Player.Weapon.Axe"))

	//**event input tags**//
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Weapon_Axe,TEXT("Player.Event.Equip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquip_Weapon_Axe,TEXT("Player.Event.UnEquip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitPause,TEXT("Player.Event.HitPause"))
	


	//**shared Event input tags**//
	UE_DEFINE_GAMEPLAY_TAG(Shared_Attack_MeeleAttack,TEXT("Shared.Attack.MeeleAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage,TEXT("Shared.SetByCaller.BaseDamage"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact_LightAttack,TEXT("Shared.Event.HitReact.LightAttack"))
    UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact_HeavyAttack,TEXT("Shared.Event.HitReact.HeavyAttack"))

	//** Ability Input Tags**//
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Weapon_Axe,TEXT("Player.Ability.Equip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_UnEquip_Weapon_Axe,TEXT("Player.Ability.UnEquip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_LightAttack_Axe,TEXT("Player.Ability.Attack.LightAttack.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_HeavyAttack_Axe,TEXT("Player.Ability.Attack.HeavyAttack.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackTypes_LightAttack,TEXT("Player.SetByCaller.AttackTypes.LightAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackTypes_HeavyAttack,TEXT("Player.SetByCaller.AttackTypes.HeavyAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact_HeavyAttack,TEXT("Shared.Ability.HitReact.HeavyAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact_LightAttack,TEXT("Shared.Ability.HitReact.LightAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause,TEXT("Player.Ability.HitPause"))

	//**Enemy Ability Tags**//
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee,TEXT("Enemy.Ability.Melee"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged,TEXT("Enemy.Ability.Ranged"))

	//** Sate Machine Tags**//
	UE_DEFINE_GAMEPLAY_TAG(Player_State_JumpToFinisher_Axe,TEXT("Player.State.JumpToFinisher.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_State_Invulnerability,TEXT("Enemy.State.Invulnerability"))

	//** Enemy Weapon Tags**//
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon_SpikedBat,TEXT("Enemy.Weapon.SpikedBat"))
}
