// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "MorrowBoneCombatComponent.generated.h"

class AWeaponMorrowBone;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	AWeaponMorrowBone* GetMorrowBoneWeaponCarriedByTag(FGameplayTag InInputTag) const;

	UFUNCTION(BlueprintPure,Category="MorrowBoneCombatComponent|HeroEquippedWeapon")
	AWeaponMorrowBone* GetMorrowBoneCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintPure,Category="MorrowBoneCombatComponent|WeaponBaseDamage")
	float GetMorrowBoneWeaponBaseDamageByLevel(float level);

	virtual void OnWeaponHitTarget(AActor* HitActor) override;
	virtual void OnWeaponPulledFromFromTarget(AActor* HitActor) override;
	
};
