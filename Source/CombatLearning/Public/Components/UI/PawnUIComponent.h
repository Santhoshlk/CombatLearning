// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnHelperComponent.h"
#include "PawnUIComponent.generated.h"
//for BroadCasting use Dynamic Multicast delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FonPercentageUpdatedDelegate,float,percentage);
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UPawnUIComponent : public UPawnHelperComponent
{
	GENERATED_BODY()

public:
	//use Blueprint Assignable for MultiCast Delegates 
	UPROPERTY(BlueprintAssignable)
	FonPercentageUpdatedDelegate CurrentHealthPercentage;
};
