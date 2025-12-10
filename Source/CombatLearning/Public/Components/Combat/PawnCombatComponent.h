// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnHelperComponent.h"
#include "PawnCombatComponent.generated.h"

class AWeaponBase;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UPawnCombatComponent : public UPawnHelperComponent
{
	GENERATED_BODY()
public:
  UFUNCTION(BlueprintCallable,Category="MorrowBone|Weapons")
	void RegisterSpawnedWeapons(FGameplayTag InputRegisterTag,AWeaponBase* WeaponToRegister,bool IsWeaponEquipped=false) ;
	UFUNCTION(BlueprintCallable)
    AWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InputTag);	
	
	UPROPERTY(BlueprintReadWrite,Category="MorrowBone|Tags")
	FGameplayTag CurrentEquippedWeaponTag;
	
	UFUNCTION(BlueprintCallable,Category="MorrowBone|Weapons")
	AWeaponBase* GetCharacterCurrentWeapon() const;
private:
	UPROPERTY()
	TMap<FGameplayTag,AWeaponBase*> RegisteredWeapons;
};
