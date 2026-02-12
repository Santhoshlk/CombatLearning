// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

struct FAIStimulus;
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
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

	

protected:

	//U can Modify Engine Components like Crowd Following Component in Begin pLay
    virtual void BeginPlay() override;

	
	// U need AIPerception Component and AISenseConfig_SightComponent to identify pawns

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UAIPerceptionComponent> EnemyPerceptionComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UAISenseConfig_Sight> EnemyAISight;

	UFUNCTION()
	virtual void OnTargetPerceptionUpdate( AActor* Actor, FAIStimulus Stimulus);

private:
 // all the variables
	UPROPERTY(EditDefaultsOnly,Category="AIDetourAvoidance")
	bool bDetourAIAvoidanceActivated;

	//Switch takes an int/Enum
	UPROPERTY(EditDefaultsOnly, Category="AIDetourAvoidance", meta=(EditCondition= "bDetourAIAvoidanceActivated",UIMin="1" ,UIMax="4"))
	int32 CrowdAvoidanceQuality;

	UPROPERTY(EditDefaultsOnly, Category="AIDetourAvoidance",meta=(EditCondition= "bDetourAIAvoidanceActivated"))
	float CrowdAvoidanceCollisionQueryRange= 500.f;
};
