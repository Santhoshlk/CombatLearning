// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WeaponStruct/WeaponStructTypes.h"
#include "MorrowBoneAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnPressed(FGameplayTag InInputTag);
	void OnReleased(FGameplayTag InInputTag);

	//create a function to give the asc by taking GameplayAbilities input
	UFUNCTION(BlueprintCallable,Category="ASC|WeaponData",meta=(ApplyLevel="1"))
	void GiveWeaponAbilitiestoASC(const  TArray<FMorrowBoneAbilitySet>& WeaponGameplayAbilities,int32 ApplyLevel,TArray<FGameplayAbilitySpecHandle>& OutGrantedSpecHandle) ;

	UFUNCTION(BlueprintCallable,Category="ASC|WeaponData")
	void RemoveWeaponGameplayAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& OutGrantedWeaponAbilitySpecHandle);
};
