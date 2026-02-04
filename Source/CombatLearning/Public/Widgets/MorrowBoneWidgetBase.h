// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MorrowBoneWidgetBase.generated.h"

class UEnemyUIComponent;
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

    // Create a Blueprint Callable Func To take an Actor In and Get Cst to Interface
	UFUNCTION(BlueprintCallable,Category = "Widget|EnemyUIComponent")
	void InitEnemyWidget(AActor* Enemy);
	
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "GetEnemyUIComponent AS Initialized"))
	void BP_GetEnemyUIComponentWhenInitialized(UEnemyUIComponent* EnemyUIComponent);
	
};
