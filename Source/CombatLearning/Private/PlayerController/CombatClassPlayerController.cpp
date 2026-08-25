// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/CombatClassPlayerController.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

ACombatClassPlayerController::ACombatClassPlayerController()
{
	MorrowBoneTeamId = FGenericTeamId(2);
}

FGenericTeamId ACombatClassPlayerController::GetGenericTeamId() const
{
	return MorrowBoneTeamId;
}

void ACombatClassPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	//u have to call a function on Gameplay statistics

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClassWithTag(this,ACameraActor::StaticClass(),FName("ViewCamera"),FoundActors);
   if (FoundActors.IsEmpty())
   {
	   return;
   }
	SetViewTarget(FoundActors[0]);
	
}
