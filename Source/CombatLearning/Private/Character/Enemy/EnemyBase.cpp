// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/EnemyBase.h"

#include "Components/Combat/EnemyCombatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyBase::AEnemyBase()
{
	// now lets setup  enemy character
	//this is to ensure that our enemy is controlled after spawning to the world
	AutoPossessAI=EAutoPossessAI::PlacedInWorldOrSpawned;

	// to set the 3rd person camera
	bUseControllerRotationPitch=false;
	bUseControllerRotationYaw=false;
	bUseControllerRotationRoll=false;

	//to set up the free camera and other properties
	GetCharacterMovement()->bUseControllerDesiredRotation=false;
	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.f,180.f,0.f);
	GetCharacterMovement()->MaxWalkSpeed=400.f;
	GetCharacterMovement()->BrakingDecelerationWalking=1000.f;

	//creating the Subobject of Combat component
	EnemyCombatComponent=CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));
}
