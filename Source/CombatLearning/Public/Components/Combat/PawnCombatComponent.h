// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnHelperComponent.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWeaponBase;
/**
 * 
 */

UENUM(BlueprintType)
enum class EWeaponEquippedTypes : uint8
{
	CurrentWeaponEquipped,
	LeftHanded,
	RightHanded
};
UCLASS()
class COMBATLEARNING_API UPawnCombatComponent : public UPawnHelperComponent
{
	GENERATED_BODY()

public:
// we need to create functions to register the weapons and get them back using gameplay tags

	//function to Register the weapon
	UFUNCTION(BlueprintCallable,Category="Weapon|Register")
 void RegisterSpawnedWeapon(FGameplayTag InInputTag,AWeaponBase* Weapon,bool IsEquipped);

	//searching Function
	UFUNCTION(BlueprintCallable,Category="Weapon|Search")
	AWeaponBase* GetWeaponCarriedbyTag(FGameplayTag InputTag) const ;

	UFUNCTION(BlueprintCallable,Category="Weapon|Search")
	AWeaponBase* GetEquippedWeapon() const;

	// u also need to give a current weaponTag Obviously
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Weapon|CurrentWeapon")
	FGameplayTag CurrentWeaponTag;

	UFUNCTION(BlueprintCallable,Category="Combat Component|Toggle Weapon Collision")
	void ToggleWeaponCollision(bool ActiveWeaponCollision,EWeaponEquippedTypes WeaponEquippedTypes=EWeaponEquippedTypes::CurrentWeaponEquipped);

	// functions bound to hit detection Delegate
	virtual void OnWeaponHitTarget(AActor* HitActor);
	virtual void OnWeaponPulledFromFromTarget(AActor* HitActor);

protected:
	UPROPERTY()
	TArray<TObjectPtr<AActor>> OverlappedActors;
	
 private:
 //we don't need to show the TMap
UPROPERTY()
TMap<FGameplayTag,AWeaponBase*> WeaponsToRegister;
	
};
