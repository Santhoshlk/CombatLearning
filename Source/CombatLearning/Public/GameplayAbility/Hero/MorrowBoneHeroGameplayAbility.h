// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/MorrowBoneGameplayAbility.h"
#include "MorrowBoneHeroGameplayAbility.generated.h"

class UMorrowBoneCombatComponent;
class ACombatClassPlayerController;
class AMorrowBone;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneHeroGameplayAbility : public UMorrowBoneGameplayAbility
{
	GENERATED_BODY()

public:
	//generally all the functions u use in the blueprint u keep them in public
    UFUNCTION(BlueprintPure,Category="GameplayAbility|Character")
	AMorrowBone* GetMorrowBoneCharacter() ;

	UFUNCTION(BlueprintPure,Category="GameplayAbility|PlayerController")
	ACombatClassPlayerController* GetMorrowBonePlayerController();	

	UFUNCTION(BlueprintPure,Category="GameplayAbility|CombatComponent")
	UMorrowBoneCombatComponent* GetMorrowBoneCombatComponent();
private:
	TWeakObjectPtr<AMorrowBone> CachedCharacter;
	TWeakObjectPtr<ACombatClassPlayerController> CachedPlayerController;
};
