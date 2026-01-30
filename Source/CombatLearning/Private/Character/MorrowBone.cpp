// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MorrowBone.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Combat/MorrowBoneCombatComponent.h"
#include "Components/UI/MorrowBoneUIComponent.h"
#include "DataAssets/InputConfig_DataAsset.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputComponent/MorrowBoneInputComponent.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"
#include "DataAssets/StartUpData/DataAsset_StartupData.h"


AMorrowBone::AMorrowBone()
{
	//get Set the size and Half Height
	Capsule=GetCapsuleComponent();
	SetRootComponent(Capsule);

	//attach the skeleton Mesh to Capsule
	SkeletonMesh=GetMesh();
	SkeletonMesh->SetupAttachment(Capsule);

	//before creating the spring arm first set The Rotation of the Character none
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// now set the Spring Arm to Rotate and of course create it
	SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bUsePawnControlRotation  = true;
	// now create the follow camera and do have it no rotation
	FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->bUsePawnControlRotation = false;

	//Create the combat component
    CombatComponent=CreateDefaultSubobject<UMorrowBoneCombatComponent>(TEXT("CombatComponent"));

	//create the UI Component
   MorrowBoneUIComponent = CreateDefaultSubobject<UMorrowBoneUIComponent>(TEXT("UIComponent"));
	
	//setup Attachments of both Camera and spring Arm
	SpringArm->SetupAttachment(Capsule);
	FollowCamera->SetupAttachment(SpringArm,USpringArmComponent::SocketName);

	//now have the character only orient to move
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//some settings to make the things better
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	GetCharacterMovement()->BrakingDecelerationWalking=2000.f;
	
	
}

void AMorrowBone::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
}

UPawnCombatComponent* AMorrowBone::GetPawnCombatComponent() const
{
	return CombatComponent;
}

UPawnUIComponent* AMorrowBone::GetPawnUIComponent() const
{
	return GetMorrowBoneUIComponent();
}

UMorrowBoneUIComponent* AMorrowBone::GetMorrowBoneUIComponentFromActor() const
{
	return GetMorrowBoneUIComponent();
}

void AMorrowBone::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	APlayerController* PlayerController=Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* SubSystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	check(SubSystem);
	SubSystem->AddMappingContext(InputConfig->InputMappingContext,0);

	//now normally are going to cast to EnhancedInputComponent But Now WE are going To Cast to Our Custom Input Component
	UMorrowBoneInputComponent* PlayerComponent=CastChecked<UMorrowBoneInputComponent>(PlayerInputComponent);
	PlayerComponent->BindingInputs(InputConfig,MorrowBoneGameplayTags::InputTag_Look,ETriggerEvent::Triggered,this,&AMorrowBone::Looking);
	PlayerComponent->BindingInputs(InputConfig,MorrowBoneGameplayTags::InputTag_Move,ETriggerEvent::Triggered,this,&AMorrowBone::Moving);
	PlayerComponent->BindAbilityInputAction(InputConfig,this,&AMorrowBone::AbilityInputAction_Pressed,&AMorrowBone::AbilityInputAction_Released);
}

void AMorrowBone::Looking(const FInputActionValue& Value)
{
	const FVector2D Look= Value.Get<FVector2D>();
	AddControllerYawInput(Look.X);
	AddControllerPitchInput(Look.Y);
}

void AMorrowBone::Moving(const FInputActionValue& Value)
{
	const FVector2D Movement= Value.Get<FVector2D>();
    FRotator CurrentRotation=GetController()->GetControlRotation();
	FRotator YawRotation(0.0f,CurrentRotation.Yaw,0.0f);
	FVector ForwardVector=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardVector,Movement.Y);
	FVector RightVector=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightVector,Movement.X);
}

void AMorrowBone::AbilityInputAction_Pressed(FGameplayTag InInputTag)
{
	AbilitySystemComponent->OnPressed(InInputTag);
}

void AMorrowBone::AbilityInputAction_Released(FGameplayTag InInputTag)
{
}


void AMorrowBone::BeginPlay()
{
	Super::BeginPlay();

	//** Note :**//
	  //We are doing in begin play as this will not be called twice as in Possessed by it called Multiple time
	// This reduces errors.
	// we need to check that our DataAsset is not null and need to load is Synchronously

	
	if (!StartUpData.IsNull())
	{
		if (UDataAsset_StartupData* LoadedData=StartUpData.LoadSynchronous())
		{
			LoadedData->GiveToASC(AbilitySystemComponent);
		}
		// the startup data is loaded in character so asc will be give by character so just if ur making a data take asc as an input and make the function
	}
	
}
