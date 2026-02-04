// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/EnemyBase.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "Components/UI/EnemyUIComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/StartUpData/DataAsset_StartupDataEnemy.h"


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

	//Create the enemy UI Component
	EnemyUIComponent=CreateDefaultSubobject<UEnemyUIComponent>(TEXT("UIComponent"));
}

UPawnCombatComponent* AEnemyBase::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

UPawnUIComponent* AEnemyBase::GetPawnUIComponent() const
{
	return GetEnemyUIComponent();
}

UEnemyUIComponent* AEnemyBase::GetEnemyUIComponentFromActor() const
{
	return GetEnemyUIComponent();
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	// call the asynchronous Loading
	AsynchronousLoadStartUpData();
}

void AEnemyBase::AsynchronousLoadStartUpData()
{

	if (StartUpData.IsNull())
	{
		  return;
	}
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
	  StartUpData.ToSoftObjectPath(),FStreamableDelegate::CreateLambda(
       [this]()
       {
	       // this is for the function Definition
       	   if ( UDataAsset_StartupData* LoadedData=StartUpData.Get())
       	   {
	       	   LoadedData->GiveToASC(AbilitySystemComponent);
       	   }

       	 
       }
	  )
		);
}
