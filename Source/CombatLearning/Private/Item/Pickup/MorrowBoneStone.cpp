// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Pickup/MorrowBoneStone.h"

#include "NiagaraComponent.h"


// Sets default values
AMorrowBoneStone::AMorrowBoneStone()
{
	
	PrimaryActorTick.bCanEverTick = false;
	StoneNiagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("StoneMesh"));
	StoneNiagara->SetupAttachment(RootComponent);
}

void AMorrowBoneStone::PickupInteraction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}



