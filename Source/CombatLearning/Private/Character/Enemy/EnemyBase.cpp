// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/EnemyBase.h"

#include "MorrowBoneFunctionLibrary.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "Components/UI/EnemyUIComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/StartUpData/DataAsset_StartupDataEnemy.h"
#include "Widgets/MorrowBoneWidgetBase.h"


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

	//Creating the Enemy Health Widget Component
	EnemyHealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("EnemyHealthWidgetComponent"));

	EnemyHealthWidgetComponent->SetupAttachment(GetMesh());

   LeftHandCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftHandCollisionBox"));
   LeftHandCollisionBox->SetupAttachment(GetMesh());
   LeftHandCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
   LeftHandCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this,&ThisClass::AEnemyBase::OnCollisionBoxOverlap);	

	RightHandCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RightHandCollisionBox"));
	RightHandCollisionBox->SetupAttachment(GetMesh());
	RightHandCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightHandCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this,&ThisClass::AEnemyBase::OnCollisionBoxOverlap);
	
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

void AEnemyBase::OnCollisionBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
  // handle the value and send it to Enemy Combat Component
	if (APawn* HitPawn  = Cast<APawn>(OtherActor))
	{
		// Check Hostility
		if (UMorrowBoneFunctionLibrary::IsTargetPawnHostile(this,HitPawn))
		{
			EnemyCombatComponent->OnWeaponHitTarget(HitPawn);
		}
	}
	
}

#if WITH_EDITOR
void AEnemyBase::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
 


	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass,RightCollisionBox))
	{
		RightHandCollisionBox->AttachToComponent(GetMesh(),FAttachmentTransformRules::SnapToTargetNotIncludingScale,RightCollisionBox);
 	
	}


	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass,LeftCollisionBox))
	{
		LeftHandCollisionBox->AttachToComponent(GetMesh(),FAttachmentTransformRules::SnapToTargetNotIncludingScale,LeftCollisionBox);
 	
	}
	
}
#endif

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

	// u can add the Blueprint Implementable Event in here
	if (UMorrowBoneWidgetBase* WidgetBase = Cast<UMorrowBoneWidgetBase>(EnemyHealthWidgetComponent->GetUserWidgetObject()))
	{
		WidgetBase->InitEnemyWidget(this);
	}
}
