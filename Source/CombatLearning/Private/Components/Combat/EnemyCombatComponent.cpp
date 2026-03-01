// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"
#include "CombatDebugHelper.h"

void UEnemyCombatComponent::OnWeaponHitTarget(AActor* HitActor)
{
	if (HitActor)
	{
		Debug::PrintMessage(GetOwningPawn()->GetActorNameOrLabel()+TEXT("HIts the Actor")+HitActor->GetActorNameOrLabel());
	}
}
