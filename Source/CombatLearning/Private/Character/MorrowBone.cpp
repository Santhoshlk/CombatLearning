// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MorrowBone.h"
#include "CombatDebugHelper.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

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

void AMorrowBone::BeginPlay()
{
	Super::BeginPlay();
	Debug::PrintMessage(FString(TEXT("The Debug Helper is Working")));
}
