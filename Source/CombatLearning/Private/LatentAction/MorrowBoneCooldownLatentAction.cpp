// Fill out your copyright notice in the Description page of Project Settings.


#include "LatentAction/MorrowBoneCooldownLatentAction.h"
#include "CombatDebugHelper.h"


void FNativeCooldownLatentAction::Cancel()
{
	m_toCancel = true;
}

void FNativeCooldownLatentAction::UpdateOperation(FLatentResponse& Response)
{
	
	if (m_toCancel)
	{
		m_OutputCooldownActions = ECooldownActionsOutput::Canceled;

		Response.FinishAndTriggerIf(true,ExecutionFunction,OutputLink,CallBackTarget);
		return;
	}
	if (ElapsedTimeSinceStart >= m_TotalCooldownTime)
	{
		m_OutputCooldownActions = ECooldownActionsOutput::Completed;

		// this is something we call when we finish the latent action
		Response.FinishAndTriggerIf(true,ExecutionFunction,OutputLink,CallBackTarget);
		return;
	}
	if (ElapsedInterval <= m_UpdateInterval)
	{
		// Elapsed time is like delta time in tick
		ElapsedInterval+=Response.ElapsedTime();
		
	}
	else
	{
		if (m_UpdateInterval==0.f)
		{
			ElapsedTimeSinceStart+=Response.ElapsedTime();
			
		}
		else
		{
			ElapsedTimeSinceStart+=m_UpdateInterval;
		}
		m_RemainingTime = m_TotalCooldownTime - ElapsedTimeSinceStart;
		
		m_OutputCooldownActions = ECooldownActionsOutput::Updated;
		// u just want to call trigger
		Response.TriggerLink(ExecutionFunction,OutputLink,CallBackTarget);
	}
	
}
