// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "Widgets/CommonUI/Widget_ConformationScreen.h"

UConformationScreenInitObject* UConformationScreenInitObject::CreateConfirmOkScreen(const FText& Title,
	const FText& Message)
{
	UConformationScreenInitObject* InitObject = NewObject<UConformationScreenInitObject>();
	
	InitObject->ScreenMessage =  Message;
	InitObject->ScreenTitle = Title;
	
	// the buttons
	FConfirmScreenButtonInfo OkButtonInfo;
	OkButtonInfo.ButtonName = FText::FromString("Ok");
	OkButtonInfo.ButtonType = EConformationScreenButtonType::Close;
	
	InitObject->Buttons.Add(OkButtonInfo);
	return InitObject;
}

UConformationScreenInitObject* UConformationScreenInitObject::CreateConfirmYesNoScreen(const FText& Title,
	const FText& Message)
{
	
	UConformationScreenInitObject* InitObject = NewObject<UConformationScreenInitObject>();
	
	InitObject->ScreenMessage =  Message;
	InitObject->ScreenTitle = Title;
	
	FConfirmScreenButtonInfo YesButtonInfo;
	YesButtonInfo.ButtonName = FText::FromString("Yes");
	YesButtonInfo.ButtonType = EConformationScreenButtonType::Confirm;
	
	InitObject->Buttons.Add(YesButtonInfo);
	
	FConfirmScreenButtonInfo NoButtonInfo;
	NoButtonInfo.ButtonName = FText::FromString("No");
	NoButtonInfo.ButtonType = EConformationScreenButtonType::Cancel;
	InitObject->Buttons.Add(NoButtonInfo);
	
	return InitObject;
}

UConformationScreenInitObject* UConformationScreenInitObject::CreateConfirmCancelScreen(const FText& Title,
	const FText& Message)
{
	UConformationScreenInitObject* InitObject = NewObject<UConformationScreenInitObject>();
	
	InitObject->ScreenMessage =  Message;
	InitObject->ScreenTitle = Title;
	
	
	FConfirmScreenButtonInfo ConfirmScreenButtonInfo;
	ConfirmScreenButtonInfo.ButtonName = FText::FromString("Confirm");
	ConfirmScreenButtonInfo.ButtonType = EConformationScreenButtonType::Confirm;
	
	InitObject->Buttons.Add(ConfirmScreenButtonInfo);
	
	FConfirmScreenButtonInfo CancelButtonInfo;
	CancelButtonInfo.ButtonName = FText::FromString("Cancel");
	CancelButtonInfo.ButtonType = EConformationScreenButtonType::Cancel;
	InitObject->Buttons.Add(CancelButtonInfo);
	
	return InitObject;
}
