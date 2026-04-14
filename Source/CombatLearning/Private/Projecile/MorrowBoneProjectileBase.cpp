// Fill out your copyright notice in the Description page of Project Settings.


#include "Projecile/MorrowBoneProjectileBase.h"

#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


AMorrowBoneProjectileBase::AMorrowBoneProjectileBase()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create the required Components SubObjects

	ProjectileBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ProjectileBoxCollision"));
	SetRootComponent(ProjectileBoxCollision);
	// Set the Properties
	ProjectileBoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ProjectileBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECR_Block);
	ProjectileBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic,ECR_Block);
	ProjectileBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic,ECR_Block);
	ProjectileNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ProjectileNiagaraComponent"));
    ProjectileNiagaraComponent->SetupAttachment(GetRootComponent());
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));

	// Set things here
	ProjectileMovementComponent->InitialSpeed = 750.f;
	ProjectileMovementComponent->MaxSpeed = 900.f;
	ProjectileMovementComponent->Velocity = FVector(1.0f,0.0f,0.0f);
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	//set initial Life Span as this needs to die
	InitialLifeSpan = 4.f;
	
	
}


void AMorrowBoneProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}


