// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneBaseAnimInstance.h"
#include "MorrowBoneLinkedAnimLayer.generated.h"

class UMorrowBoneHeroAnimInstance;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneLinkedAnimLayer : public UMorrowBoneBaseAnimInstance
{
	GENERATED_BODY()

public:
	// If u want a variable to come in property access it better to keep Thread Safe Access
	UFUNCTION(BlueprintPure,meta=(BlueprintThreadSafe))
	UMorrowBoneHeroAnimInstance* GetHeroAnimInstance() const;
	
	
};
