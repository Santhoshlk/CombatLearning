// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	// I want to Change the Base Component Given by AIController
	//Use const FObject Initializer
	AEnemyAIController(const FObjectInitializer& ObjectInitializer );
	
};
