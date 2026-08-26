// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Widget_PrimaryWidgetLayout.generated.h"

/**
 * 
 */
class UCommonActivatableWidgetContainerBase;

// let this class be abstract and no  native tick
UCLASS(Abstract,meta=(DisableNativeTick))
class COMBATLEARNING_API UWidget_PrimaryWidgetLayout : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	//getter for the common activatable widget container base
	UCommonActivatableWidgetContainerBase* GetWidgetStack(const FGameplayTag InStackTag);

protected:
	
 // register function
	UFUNCTION(BlueprintCallable,Category = "WidgetLayout")
	void RegisterWidgetStacks( UPARAM(meta = (Categories = "Frontend.WidgetStack.")) FGameplayTag InStackTag,  UCommonActivatableWidgetContainerBase* const InStack);

	
private:
	// create ur map which store widgets
	UPROPERTY(Transient)
	TMap<FGameplayTag,UCommonActivatableWidgetContainerBase*> WidgetStackMap;
};
