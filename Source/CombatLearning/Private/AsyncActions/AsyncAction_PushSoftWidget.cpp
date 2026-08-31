// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "AsyncActions/AsyncAction_PushSoftWidget.h"

UAsyncAction_PushSoftWidget* UAsyncAction_PushSoftWidget::PushSoftWidgetToStack(const UObject* WorldContextObject,
	UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag FrontendUITag, TSoftClassPtr<UWidget_ActivatableBase> SoftWidgetClass, bool FocusOnPushedWidget)
{
   checkf(!SoftWidgetClass.IsNull() && FrontendUITag.IsValid(),TEXT("The Tag and the Widget Class that u send should be valid"));

	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject,EGetWorldErrorMode::LogAndReturnNull))
		{
			UAsyncAction_PushSoftWidget* AsyncAction = NewObject<UAsyncAction_PushSoftWidget>();
			AsyncAction->RegisterWithGameInstance(World->GetGameInstance());
			return AsyncAction;
		}
	}
	
	return nullptr;
}
