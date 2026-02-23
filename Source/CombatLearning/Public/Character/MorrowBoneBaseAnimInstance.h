// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "MorrowBoneBaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintPure,meta=(BlueprintThreadSafe))
	bool DoesOurPawnHaveTag(const FGameplayTag InInputTag) const ;
};
