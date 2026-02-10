// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/EnemyAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
// #include "CombatDebugHelper.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer& ObjectInitializer):
 Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	if ( UCrowdFollowingComponent* CrowdFollowingComponent =Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		// Debug::PrintMessage(TEXT("CrowdFollowingComponent is Valid "));
	}

	//Create the Components
	EnemyAISight=CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("EnemyAISight"));

	//SettingPrimaryProperties
	EnemyAISight->DetectionByAffiliation.bDetectEnemies = true;
	EnemyAISight->DetectionByAffiliation.bDetectFriendlies = false;
	EnemyAISight->DetectionByAffiliation.bDetectNeutrals = false;
	EnemyAISight->SightRadius = 750.f;
	EnemyAISight->LoseSightRadius = 0.f;
	//Depends on the Type of game
	EnemyAISight->PeripheralVisionAngleDegrees= 360.f;

	//Sense is In Perception Component 
	EnemyPerceptionComponent=CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("EnemyPerceptionComponent"));
	EnemyPerceptionComponent->ConfigureSense(*EnemyAISight);
	EnemyPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	EnemyPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this,&ThisClass::AEnemyAIController::OnTargetPerceptionUpdate);
}

void AEnemyAIController::OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
}
