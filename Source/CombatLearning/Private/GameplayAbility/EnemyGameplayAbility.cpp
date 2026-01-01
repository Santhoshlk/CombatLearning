// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/EnemyGameplayAbility.h"
#include "Character/Enemy/EnemyBase.h"

AEnemyBase* UEnemyGameplayAbility::GetEnemyCharacter() 
{
	if (!CachedEnemy.IsValid())
	{
		CachedEnemy=Cast<AEnemyBase>(CurrentActorInfo->AvatarActor);
	}
	return CachedEnemy.Get();
}

UEnemyCombatComponent* UEnemyGameplayAbility::GetEnemyCombatComponent() const
{
	if (CachedEnemy.IsValid())
	{
		return CachedEnemy->GetEnemyCombatComponent();
	}
	return nullptr;
}
