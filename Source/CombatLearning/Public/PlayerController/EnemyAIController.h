// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UAISenseConfig_Sight;
/**
 * 
 */
class UAIPerceptionComponent; 
UCLASS()
class COMBATLEARNING_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	// I want to Change the Base Component Given by AIController
	//Use const FObject Initializer
	AEnemyAIController(const FObjectInitializer& ObjectInitializer );

protected:
	// U need AIPerception Component and AISenseConfig_SightComponent to identify pawns

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UAIPerceptionComponent> EnemyPerceptionComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UAISenseConfig_Sight> EnemyAISight;

	UFUNCTION()
	virtual void OnTargetPerceptionUpdate( AActor* Actor, FAIStimulus Stimulus);
};
