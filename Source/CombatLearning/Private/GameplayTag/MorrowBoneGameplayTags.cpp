// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTag/MorrowBoneGameplayTags.h"

//** now that we have declared the GameplayTags Under the Namespace Just Define Them using the same Unreal Definition**\\

namespace MorrowBoneGameplayTags
{
	// to define the game play tags u don't need the project name
	//adopt the dot system
	//Here the Tag name is the Literal Name you are going to see in the editor
  UE_DEFINE_GAMEPLAY_TAG(InputTag_Move,TEXT("InputTag.Move"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look,TEXT("InputTag.Look"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip_Axe,TEXT("InputTag.Equip.Axe"))
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquip_Axe,TEXT("InputTag.UnEquip.Axe"))

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,TEXT("Player.Weapon.Axe"))
	
	//here we are declaring new Gameplay Tag for our weapon spawned
	
}
