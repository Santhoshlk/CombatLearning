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
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Roll,TEXT("InputTag.Roll"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SwitchTargets,TEXT("InputTag.SwitchTargets"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_ToggleAbility_Rage,TEXT("InputTag.ToggleAbility.Rage"))

	//**ability input tags**//
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip_Axe,TEXT("InputTag.Equip.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquip_Axe,TEXT("InputTag.UnEquip.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe,TEXT("InputTag.LightAttack.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe,TEXT("InputTag.HeavyAttack.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Health_Low,TEXT("Enemy.Health.Low"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld,TEXT("InputTag.MustBeHeld"))
    UE_DEFINE_GAMEPLAY_TAG(InputTag_MustBeHeld_Block,TEXT("InputTag.MustBeHeld.Block"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_ToggleAbility,TEXT("InputTag.ToggleAbility"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_ToggleAbility_TargetLock,TEXT("InputTag.ToggleAbility.TargetLock"))

	//**weapon input tags**//
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,TEXT("Player.Weapon.Axe"))

	//**event input tags**//
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Weapon_Axe,TEXT("Player.Event.Equip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquip_Weapon_Axe,TEXT("Player.Event.UnEquip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitPause,TEXT("Player.Event.HitPause"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitReact,TEXT("Player.Event.HitReact"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SuccessfulBlock,TEXT("Player.Event.SuccessfulBlock"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SwitchTarget_Right,TEXT("Player.Event.SwitchTarget.Right"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SwitchTarget_Left,TEXT("Player.Event.SwitchTarget.Left"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_RageActivation,TEXT("Player.Event.RageActivation"))
	
	


	//**shared Event input tags**//
	UE_DEFINE_GAMEPLAY_TAG(Shared_Attack_MeeleAttack,TEXT("Shared.Attack.MeeleAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage,TEXT("Shared.SetByCaller.BaseDamage"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact_LightAttack,TEXT("Shared.Event.HitReact.LightAttack"))
    UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact_HeavyAttack,TEXT("Shared.Event.HitReact.HeavyAttack"))
   UE_DEFINE_GAMEPLAY_TAG(Shared_Event_SpawnProjectile,TEXT("Shared.Event.SpawnProjectile"))
	
	//** Ability Input Tags**//
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Weapon_Axe,TEXT("Player.Ability.Equip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_UnEquip_Weapon_Axe,TEXT("Player.Ability.UnEquip.Weapon.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_LightAttack_Axe,TEXT("Player.Ability.Attack.LightAttack.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_HeavyAttack_Axe,TEXT("Player.Ability.Attack.HeavyAttack.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackTypes_LightAttack,TEXT("Player.SetByCaller.AttackTypes.LightAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackTypes_HeavyAttack,TEXT("Player.SetByCaller.AttackTypes.HeavyAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause,TEXT("Player.Ability.HitPause"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Roll,TEXT("Player.Ability.Roll"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitReact,TEXT("Player.Ability.HitReact"))
    UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Block,TEXT("Player.Ability.Block"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_TargetLock,TEXT("Player.Ability.TargetLock"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Rage,TEXT("Player.Ability.Rage"))
	
	//**Tags For Shared Abilities **//
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact_HeavyAttack,TEXT("Shared.Ability.HitReact.HeavyAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact_LightAttack,TEXT("Shared.Ability.HitReact.LightAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death,TEXT("Shared.Ability.Death"))

	//**Enemy Ability Tags**//
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee,TEXT("Enemy.Ability.Melee"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee_1,TEXT("Enemy.Ability.Melee.1"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee_2,TEXT("Enemy.Ability.Melee.2"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee_3,TEXT("Enemy.Ability.Melee.3"))
	 UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_SummonEnemies,TEXT("Enemy.Ability.SummonEnemies"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged,TEXT("Enemy.Ability.Ranged"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_SetByCaller_Melee,TEXT("Enemy.SetByCaller.Melee"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Attack_Blockable,TEXT("Enemy.Attack.Blockable"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Attack_UnBlockable,TEXT("Enemy.Attack.UnBlockable"))

	//**Tags for Enemies Events**//
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Event_SummonEnemies,TEXT("Enemy.Event.SummonEnemies"))
	

	//** Sate Machine Tags || Status**//
	UE_DEFINE_GAMEPLAY_TAG(Player_State_JumpToFinisher_Axe,TEXT("Player.State.JumpToFinisher.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_State_Invulnerability,TEXT("Enemy.State.Invulnerability"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_State_UnderAttack,TEXT("Enemy.State.UnderAttack"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_State_Straffing,TEXT("Enemy.State.Strafing"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Death,TEXT("Shared.Status.Death"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rolling,TEXT("Player.Status.Rolling"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Front,TEXT("Shared.Status.HitReact.Front"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Back,TEXT("Shared.Status.HitReact.Back"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Left,TEXT("Shared.Status.HitReact.Left"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Right,TEXT("Shared.Status.HitReact.Right"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Block,TEXT("Player.Status.Block"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_TargetLock,TEXT("Player.Status.TargetLock"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Activating,TEXT("Player.Status.Rage.Activating"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_Active,TEXT("Player.Status.Rage.Active"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Staus_Rage_Full,TEXT("Player.Status.Rage.Full"))
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Rage_None,TEXT("Player.Status.Rage.None"))
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Invincibility,TEXT("Shared.Status.Invincibility"))

	//** Enemy Weapon Tags**//
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon_SpikedBat,TEXT("Enemy.Weapon.SpikedBat"))
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon_Wand,TEXT("Enemy.Weapon.Wand"))
}
