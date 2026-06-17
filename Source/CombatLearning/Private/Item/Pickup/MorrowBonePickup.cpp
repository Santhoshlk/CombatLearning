// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Pickup/MorrowBonePickup.h"
#include "Components/SphereComponent.h"


AMorrowBonePickup::AMorrowBonePickup()
{
	PrimaryActorTick.bCanEverTick = false;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SetRootComponent(SphereCollision);

	// u just specify these
	SphereCollision->InitSphereRadius(100.f);
	SphereCollision->OnComponentBeginOverlap.AddUniqueDynamic(this,&ThisClass::AMorrowBonePickup::PickupInteraction);
}

void AMorrowBonePickup::PickupInteraction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}


