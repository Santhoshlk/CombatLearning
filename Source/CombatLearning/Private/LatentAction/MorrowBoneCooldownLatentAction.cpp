// Fill out your copyright notice in the Description page of Project Settings.


#include "LatentAction/MorrowBoneCooldownLatentAction.h"


void FNativeCooldownLatentAction::Cancel()
{
	m_toCancel = true;
}

void FNativeCooldownLatentAction::UpdateOperation(FLatentResponse& Response)
{
  
	
	FPendingLatentAction::UpdateOperation(Response);
}
