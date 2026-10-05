// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/CommonUI/Widget_ActivatableBase.h"
#include "FrontendUIEnums.h"
#include "Widget_ConformationScreen.generated.h"

class UDynamicEntryBox;
class UCommonTextBlock;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FConfirmScreenButtonInfo
{
	GENERATED_BODY()
	
	// default public
	UPROPERTY(EditAnywhere)
	EConformationScreenButtonType ButtonType = EConformationScreenButtonType::Unknown;
	
	UPROPERTY(EditAnywhere)
	FText ButtonName;
	
	
};

 // each screen contains many info which is why we can package it in an Info Object
UCLASS(BlueprintType)
class COMBATLEARNING_API UConformationScreenInitObject : public UObject
{
	GENERATED_BODY()
public:
	// u need to create the runtime holder with static so use 
	UFUNCTION(BlueprintCallable)
	static UConformationScreenInitObject* CreateConfirmOkScreen(const FText& Title,const FText& Message);
	
	UFUNCTION(BlueprintCallable)
	static UConformationScreenInitObject* CreateConfirmYesNoScreen(const FText& Title,const FText& Message);
	
	UFUNCTION(BlueprintCallable)
	static UConformationScreenInitObject* CreateConfirmCancelScreen(const FText& Title,const FText& Message);
	
	UPROPERTY(Transient)
	FText ScreenTitle;
	
	UPROPERTY(Transient)
	FText ScreenMessage;
	
	UPROPERTY(Transient)
	TArray<FConfirmScreenButtonInfo> Buttons;
 	
};


UCLASS(Abstract,meta=(DisableNativeTick))
class COMBATLEARNING_API UWidget_ConformationScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()
	 
private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonTextBlock> Title;
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonTextBlock> Message;
	// the idea is that it in runtime allow u to add multiple items in a box
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox;
	
	
};
