// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MorrowBonePickup.h"
#include "MorrowBoneStone.generated.h"

class UNiagaraComponent;

UCLASS()
class COMBATLEARNING_API AMorrowBoneStone : public AMorrowBonePickup
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMorrowBoneStone();
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Stone")
	TObjectPtr<UNiagaraComponent> StoneNiagara;

virtual  void PickupInteraction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &  SweepResult) override;

};
