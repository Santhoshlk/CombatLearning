// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_PushSoftWidget.generated.h"

class UWidget_ActivatableBase;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAsyncPushDelegate,UWidget_ActivatableBase*,WidgetToPush);

/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UAsyncAction_PushSoftWidget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	// creation of the action
	UFUNCTION(BlueprintCallable,meta=(WorldContext = "WorldContextObject",HidePin = "WorldContextObject",BlueprintInternalUseOnly))
	static UAsyncAction_PushSoftWidget*  PushSoftWidgetToStack(const UObject* WorldContextObject,UPARAM(meta = (Categories = "Frontend.WidgetStack"))FGameplayTag FrontendUITag,
     TSoftClassPtr<UWidget_ActivatableBase> SoftWidgetClass,
     bool FocusOnPushedWidget = true
	);

	// in async actions if u just create a delegate Instance and just keep them they are auto bind as outputs
	UPROPERTY(BlueprintAssignable)
	FOnAsyncPushDelegate BeforePush;
	UPROPERTY(BlueprintAssignable)
	FOnAsyncPushDelegate AfterPush;
};
