// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Widgets/CommonUI/Widget_PrimaryWidgetLayout.h"
#include "FrontendUISubsystem.generated.h"

class UWidget_ActivatableBase;
class UWidget_PrimaryWidgetLayout;
struct FGameplayTag;
/**
 * 
 */
enum class EWidgetPushActionType : uint8
{
	CreatedBeforePush,
	AfterPush
};

UCLASS()
class COMBATLEARNING_API UFrontendUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	// the blueprint already has a getter for Subsystem so have one for c++
	static UFrontendUISubsystem* GetFrontendUISubsystem(const UObject* WorldContextObject);

   // so that any one which has the subsystem can get it
	// this is a cpp function
	void NativePushSoftWidgetToStack(const FGameplayTag& InWidgetTag,TSoftClassPtr<UWidget_ActivatableBase> CommonUserWidget,TFunction<void(EWidgetPushActionType PushAction,UWidget_ActivatableBase* Widget)> AsyncPushAction);

	
protected:
    // ~ Begin USubsystem Interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	//~ End USubsystem Interface

	// now just add it
	UFUNCTION(BlueprintCallable)
	void RegisterPrimaryWidgetLayout( UWidget_PrimaryWidgetLayout* CreatedPrimaryWidgetLayout);
private:
	UPROPERTY(Transient)
	TObjectPtr<UWidget_PrimaryWidgetLayout> PrimaryWidgetLayout;
};
