// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/EnemyGameplayAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
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

FGameplayEffectSpecHandle UEnemyGameplayAbility::MakeMorrowBoneDamageEffectSpecHandle(
	TSubclassOf<UGameplayEffect> EffectClass,float level, float WeaponDamage)
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
	checkf(ASC,TEXT("The ASC of the Instigator should be valid"));

	FGameplayEffectContextHandle EffectContextHandle;
	EffectContextHandle.AddInstigator(GetAvatarActorFromActorInfo(),GetAvatarActorFromActorInfo());
	EffectContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(
		EffectClass,
		level,
		EffectContextHandle
		);
	return SpecHandle;
}
