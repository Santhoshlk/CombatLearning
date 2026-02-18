// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/CombatClassPlayerController.h"

ACombatClassPlayerController::ACombatClassPlayerController()
{
	MorrowBoneTeamId = FGenericTeamId(2);
}

FGenericTeamId ACombatClassPlayerController::GetGenericTeamId() const
{
	return MorrowBoneTeamId;
}
