// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/EnemyAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "CombatDebugHelper.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer& ObjectInitializer):
 Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	if ( UCrowdFollowingComponent* CrowdFollowingComponent =Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		Debug::PrintMessage(TEXT("CrowdFollowingComponent is Valid "));
	}
}
