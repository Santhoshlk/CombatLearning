// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MorrowBone.h"
#include "CombatDebugHelper.h"

void AMorrowBone::BeginPlay()
{
	Super::BeginPlay();
	 Debug::PrintMessage(FString(TEXT("The Debug Helper is Working")));
}
