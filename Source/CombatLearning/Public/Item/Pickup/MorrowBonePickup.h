// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MorrowBonePickup.generated.h"

class USphereComponent;

UCLASS()
class COMBATLEARNING_API AMorrowBonePickup : public AActor
{
	GENERATED_BODY()

public:
	
	AMorrowBonePickup();
protected:
#pragma region Components
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Pickup")
	TObjectPtr<USphereComponent> SphereCollision;
#pragma endregion

	UFUNCTION()
	virtual void PickupInteraction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &  SweepResult);
};
