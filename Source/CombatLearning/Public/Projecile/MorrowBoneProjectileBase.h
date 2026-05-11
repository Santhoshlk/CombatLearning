// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Actor.h"
#include "MorrowBoneProjectileBase.generated.h"

class UNiagaraComponent;
class UProjectileMovementComponent;
class UBoxComponent;
struct FGameplayEffectSpecHandle;


// Enum for Activation policy
UENUM(BlueprintType)
enum class EProjectileActivationPolicy : uint8
{
	onHit,
	onOverlap
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
  UPROPERTY(VisibleAnywhere ,BlueprintReadOnly,Category = " Box Collision")
	TObjectPtr<UBoxComponent> ProjectileBoxCollision;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Projectile")
	TObjectPtr<UNiagaraComponent> ProjectileNiagaraComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
	

#pragma endregion

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Projectile")
	EProjectileActivationPolicy ActivationPolicy = EProjectileActivationPolicy::onHit;

	UPROPERTY(BlueprintReadOnly,meta=(ExposeOnSpawn = "true"))
	FGameplayEffectSpecHandle ProjectileDamageSpecHandle;

protected:
	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnProjectileOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintImplementableEvent, DisplayName="ProjectileImpactFx")
	void BP_ProjectileImpactFx(const FVector &HitLocation);

	void HandleApplyGameplayEffectSpecHandle( APawn* InPawn);
};
