// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "AsyncActions/AsyncAction_PushSoftWidget.h"

#include "Subsystems/FrontendUISubsystem.h"
#include "Widgets/CommonUI/Widget_ActivatableBase.h"

UAsyncAction_PushSoftWidget* UAsyncAction_PushSoftWidget::PushSoftWidgetToStack(const UObject* WorldContextObject,APlayerController* OwningPlayerController,
                                                                                UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag FrontendUITag, TSoftClassPtr<UWidget_ActivatableBase> SoftWidgetClass, bool FocusOnPushedWidget)
{
   checkf(!SoftWidgetClass.IsNull() && FrontendUITag.IsValid(),TEXT("The Tag and the Widget Class that u send should be valid"));

	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject,EGetWorldErrorMode::LogAndReturnNull))
		{
			UAsyncAction_PushSoftWidget* AsyncAction = NewObject<UAsyncAction_PushSoftWidget>();

			AsyncAction->CachedWorldContextObject = World;
			AsyncAction->CachedPlayerController = OwningPlayerController;
			AsyncAction->SoftWidgetClass = SoftWidgetClass;
			AsyncAction->CachedFrontendUITag = FrontendUITag;
            AsyncAction->FocusOnPushedWidget = FocusOnPushedWidget;	
			
			AsyncAction->RegisterWithGameInstance(World->GetGameInstance());
			return AsyncAction;
		}
	}
	
	return nullptr;
}

void UAsyncAction_PushSoftWidget::Activate()
{
	Super::Activate();

	UFrontendUISubsystem* FrontendUISubsystem =  UFrontendUISubsystem::GetFrontendUISubsystem(CachedWorldContextObject.Get());

	FrontendUISubsystem->NativePushSoftWidgetToStack(CachedFrontendUITag,SoftWidgetClass,

     [this](EWidgetPushActionType PushAction, UWidget_ActivatableBase* Widget)
     {
	     switch (PushAction)
	     {
	     case EWidgetPushActionType::CreatedBeforePush:
	     	if (CachedPlayerController.IsValid())
	     	{
	     		Widget->SetOwningPlayer(CachedPlayerController.Get());
	     		// broadcast the value
	     		CreatedBeforePush.Broadcast(Widget);
	     	}
	     	break;
	     case EWidgetPushActionType::AfterPush:
	     	if (FocusOnPushedWidget)
	     	{
	     		if (UWidget* FocusWidget =Widget->GetDesiredFocusTarget())
	     		{
	     			FocusWidget->SetFocus();
	     		}	
	     	}
	     	break;
	     default:
	     	break;
	     }
     }
	);

	SetReadyToDestroy();
}


