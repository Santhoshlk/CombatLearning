// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer& ObjectInitializer):
 Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	

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
	//we use a Delegate to update when the enemy character detects a hostile 
	EnemyPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this,&ThisClass::AEnemyAIController::OnTargetPerceptionUpdate);
	SetGenericTeamId(FGenericTeamId(1));
}

ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* PawnTobeChecked=Cast<const APawn>(&Other);
	const IGenericTeamAgentInterface* Agent = Cast<const IGenericTeamAgentInterface>(PawnTobeChecked->GetController());
	if (Agent && (Agent->GetGenericTeamId()!=GetGenericTeamId()))
	{
		return ETeamAttitude::Hostile;
	}
	return ETeamAttitude::Friendly;
} 

void AEnemyAIController::OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed() && Actor)
	{
		if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
		{
			BlackboardComponent->SetValueAsObject(FName("TargetActorKey"),Actor);
		}
	}
}
