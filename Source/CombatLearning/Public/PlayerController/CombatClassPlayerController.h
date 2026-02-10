// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "CombatClassPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API ACombatClassPlayerController : public APlayerController , public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ACombatClassPlayerController();
	// to actually get the Team ID so that onTargetPerception could use it
	virtual FGenericTeamId GetGenericTeamId() const override;
private:
	FGenericTeamId MorrowBoneTeamId;
};
