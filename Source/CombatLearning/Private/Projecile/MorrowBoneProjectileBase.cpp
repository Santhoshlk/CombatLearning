// Fill out your copyright notice in the Description page of Project Settings.


#include "Projecile/MorrowBoneProjectileBase.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MorrowBoneFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"


AMorrowBoneProjectileBase::AMorrowBoneProjectileBase()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create the required Components SubObjects

	ProjectileBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ProjectileBoxCollision"));
	SetRootComponent(ProjectileBoxCollision);
	// Set the Properties
	ProjectileBoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ProjectileBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECR_Block);
	ProjectileBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECR_Block);
	ProjectileBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECR_Block);
	ProjectileNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ProjectileNiagaraComponent"));
	ProjectileNiagaraComponent->SetupAttachment(GetRootComponent());
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
		TEXT("ProjectileMovementComponent"));

	// Set things here
	ProjectileMovementComponent->InitialSpeed = 750.f;
	ProjectileMovementComponent->MaxSpeed = 900.f;
	ProjectileMovementComponent->Velocity = FVector(1.0f, 0.0f, 0.0f);
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	//set initial Life Span as this needs to die
	InitialLifeSpan = 4.f;

	// Now Bind To delegates
	ProjectileBoxCollision->OnComponentHit.AddUniqueDynamic(
		this,
		&ThisClass::AMorrowBoneProjectileBase::OnProjectileHit);
	ProjectileBoxCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnProjectileOverlap);
}


void AMorrowBoneProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	if (ActivationPolicy == EProjectileActivationPolicy::onOverlap)
	{
		ProjectileBoxCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	}
}

void AMorrowBoneProjectileBase::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                                UPrimitiveComponent* OtherComp, FVector NormalImpulse,
                                                const FHitResult& Hit)
{
	// this is when u have overlapped object has hit

	BP_ProjectileImpactFx(Hit.ImpactPoint);
	// to check hit for all actors lets do the logic in hit
	APawn* HitTarget = Cast<APawn>(OtherActor);

	if (!HitTarget)
	{
		Destroy();
		return;
	}

	bool IsValidBlock = false;
	bool IsBlocking = false;
	bool IsTargetHostile = UMorrowBoneFunctionLibrary::IsTargetPawnHostile(GetInstigator(), HitTarget);
	if (IsTargetHostile)
	{
		IsBlocking = UMorrowBoneFunctionLibrary::NativeDoesActorHaveTag(
			HitTarget,
			MorrowBoneGameplayTags::Player_Status_Block);
	}
	else
	{
		Destroy();
		return;
	}
	if (IsBlocking)
	{
		IsValidBlock = UMorrowBoneFunctionLibrary::ValidBlock(this, HitTarget);
	}
	FGameplayEventData Data;
	Data.Instigator = GetInstigator();
	Data.Target = HitTarget;
	if (IsValidBlock)
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			HitTarget,
			MorrowBoneGameplayTags::Player_Event_SuccessfulBlock,
			Data
		);
	}
	else
	{
		// apply damage
		HandleApplyGameplayEffectSpecHandle(HitTarget);
	}
	Destroy();
}

void AMorrowBoneProjectileBase::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                                    bool bFromSweep, const FHitResult& SweepResult)
{
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		// Impact FX and Sound are Still valid
		BP_ProjectileImpactFx(SweepResult.ImpactPoint);

		// Apply the Damage by Gameplay Effect Spec Handle
		if (GetInstigator() != HitPawn)
			HandleApplyGameplayEffectSpecHandle(HitPawn);
	}
	else
	{
		return;
	}
}

void AMorrowBoneProjectileBase::HandleApplyGameplayEffectSpecHandle(APawn* InPawn)
{
	bool ApplyHandle = UMorrowBoneFunctionLibrary::ApplyGameplayEffectSpecHandleToTarget(
		GetInstigator(),
		InPawn,
		ProjectileDamageSpecHandle);
	FGameplayEventData Data;
	Data.Instigator = GetInstigator();
	Data.Target = InPawn;
	if (ApplyHandle)
	{
		// now apply HitReact
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			InPawn,
			MorrowBoneGameplayTags::Shared_Event_HitReact_LightAttack,
			Data
		);
	}
}
