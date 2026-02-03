// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MorrowBoneWidgetBase.generated.h"

class UMorrowBoneUIComponent;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeOnInitialized() override;
	UFUNCTION(BlueprintImplementableEvent,meta=(DisplayName="GetMorrowBoneUIComponentAtInitialized"))
	void BP_GetMorrowBoneUIComponentAtInitialized(UMorrowBoneUIComponent* MorrowBoneUIComponent);
};
