// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FrontendUIButtonBase.generated.h"

class UCommonTextBlock;
/**
 * 
 */
//Explicit blueprint type is not neccessary
UCLASS(Abstract,meta=(DisableNativeTick))
class COMBATLEARNING_API UFrontendUIButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	//~Begin UUserWidget Interface
   virtual void NativePreConstruct() override;
   //~End UUserWidget Interface

	//~Begin UCommonButtonBase Interface
	virtual void NativeOnCurrentTextStyleChanged() override;
    //~End UCommonButtonBase Interface

private:
	UPROPERTY(VisibleAnywhere,Category="Button Text",meta=(BindWidgetOptional))
	TObjectPtr<UCommonTextBlock> CommonButton_Text;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true",Category = "Button Text"))
	FText ButtonDisplayText;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true",Category = "Button Text"))
    bool bToUpper = false;
	
	UFUNCTION(BlueprintCallable)
	void SetDisplayText(FText InText);
};
