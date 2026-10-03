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
