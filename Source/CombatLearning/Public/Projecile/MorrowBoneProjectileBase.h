// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MorrowBoneProjectileBase.generated.h"

class UNiagaraComponent;
class UProjectileMovementComponent;
class UBoxComponent;

// Enum for Activation policy
UENUM(BlueprintType)
enum class EProjectileActivationPolicy : uint8
{
	onHit,
	onOverlap,
};

UCLASS()
class COMBATLEARNING_API AMorrowBoneProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMorrowBoneProjectileBase();

protected:
	
	virtual void BeginPlay() override;

#pragma region Components	
  UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Projectile")
	TObjectPtr<UBoxComponent> ProjectileBoxCollision;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Projectile")
	TObjectPtr<UNiagaraComponent> ProjectileNiagaraComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
	

#pragma endregion

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Projectile")
	EProjectileActivationPolicy Policy = EProjectileActivationPolicy::onHit;

};
