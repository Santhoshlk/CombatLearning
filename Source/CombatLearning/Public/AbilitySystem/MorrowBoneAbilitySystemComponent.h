// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
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
	
};
