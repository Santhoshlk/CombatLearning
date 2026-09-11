// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "Widgets/CommonUI/Accessories/FrontendUIButtonBase.h"

#include "CommonTextBlock.h"

void UFrontendUIButtonBase::SetDisplayText(FText InText)
{
	// as this is optional
	if (CommonButton_Text && !InText.IsEmpty())
	{
		CommonButton_Text->SetText(bToUpper ? InText.ToUpper() : InText);
	}
}

void UFrontendUIButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	// every time u make a change and compile this run
	SetDisplayText(ButtonDisplayText);
}


