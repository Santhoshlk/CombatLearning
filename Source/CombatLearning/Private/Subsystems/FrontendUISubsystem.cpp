// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "Subsystems/FrontendUISubsystem.h"

#include "CombatDebugHelper.h"
#include "Engine/AssetManager.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Widgets/CommonUI/Widget_ActivatableBase.h"

UFrontendUISubsystem* UFrontendUISubsystem::GetFrontendUISubsystem(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);
		// this won't let a nullptr

		return UGameInstance::GetSubsystem<UFrontendUISubsystem>(World->GetGameInstance());
	}
	return nullptr;
}

void UFrontendUISubsystem::NativePushSoftWidgetToStack(const FGameplayTag& InWidgetTag,
	TSoftClassPtr<UWidget_ActivatableBase> CommonUserWidget,
	TFunction<void(EWidgetPushActionType PushAction,UWidget_ActivatableBase* Widget)> AsyncPushAction
	)
{
	// first check if the class and tag are valid
	checkf(!CommonUserWidget.IsNull() && InWidgetTag.IsValid(),TEXT("The tag and the Widget Class that u give must be valid"));

	 // async load
	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
      CommonUserWidget.ToSoftObjectPath(),
      FStreamableDelegate::CreateLambda(
       [this,CommonUserWidget,InWidgetTag,AsyncPushAction]()
       {
	     UClass* LoadedWidgetClass =   CommonUserWidget.Get();
       	UCommonActivatableWidgetContainerBase* WidgetStack =  PrimaryWidgetLayout->GetWidgetStack(InWidgetTag);
      UWidget_ActivatableBase* CurrentWidget =  WidgetStack->AddWidget<UWidget_ActivatableBase>(
          LoadedWidgetClass,
          [AsyncPushAction](UWidget_ActivatableBase& InWidgetInstance)
          {
	          AsyncPushAction(EWidgetPushActionType::CreatedBeforePush,&InWidgetInstance);
          }
       	);

       	// call the function again
       	AsyncPushAction(EWidgetPushActionType::AfterPush,CurrentWidget);
       }
      )
	);
}

bool UFrontendUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
    if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
    {
    	TArray<UClass*> DerivedClasses;
	    GetDerivedClasses(GetClass(),DerivedClasses);
    	return DerivedClasses.IsEmpty();
    }
	
	return false;
}

void UFrontendUISubsystem::RegisterPrimaryWidgetLayout( UWidget_PrimaryWidgetLayout* CreatedPrimaryWidgetLayout)
{
	checkf(CreatedPrimaryWidgetLayout,TEXT("The Primary WidgetLayout should be valid"));

	PrimaryWidgetLayout = CreatedPrimaryWidgetLayout;
	
}

