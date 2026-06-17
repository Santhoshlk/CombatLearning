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



