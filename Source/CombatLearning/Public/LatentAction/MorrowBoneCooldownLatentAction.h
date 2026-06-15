// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MorrowBoneEnums.h"

class FNativeCooldownLatentAction : public FPendingLatentAction
{
  bool m_toCancel;
	float m_TotalCooldownTime;
	float m_UpdateInterval;
	float& m_RemainingTime;
	ECooldownActionsOutput& m_OutputCooldownActions;
	// these are latent input action connections
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallBackTarget;
	float ElapsedInterval;
	float ElapsedTimeSinceStart;

	
public:
	FNativeCooldownLatentAction(float TotalCooldownTime,float UpdateInterval,float& RemainingTime,ECooldownActionsOutput& OutputCooldownActions,FLatentActionInfo LatentActionInfo) :m_toCancel(false),m_TotalCooldownTime(TotalCooldownTime),
	m_UpdateInterval(UpdateInterval),m_RemainingTime(RemainingTime),m_OutputCooldownActions(OutputCooldownActions),
	ExecutionFunction(LatentActionInfo.ExecutionFunction),
	OutputLink(LatentActionInfo.Linkage),
	CallBackTarget(LatentActionInfo.CallbackTarget),
	ElapsedInterval(0.f),
	ElapsedTimeSinceStart(0.f)
	{
		
	}

void Cancel();
	
	virtual void UpdateOperation(FLatentResponse& Response) override;
};
