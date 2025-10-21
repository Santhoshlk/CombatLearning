// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneClassBase.h"
#include "MorrowBone.generated.h"

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API AMorrowBone : public AMorrowBoneClassBase
{
	GENERATED_BODY()
public:
	// u can still have Begin play even if u delete it from the base class it is a right of every unreal class
	virtual void BeginPlay() override;
};
