// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MorrowBoneWidgetBase.h"

#include "Interface/PawnUIInterface.h"


void UMorrowBoneWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// now when the Widget gets initialized then we can get the holding of UI component and the values it Broadcasts
	if (IPawnUIInterface* PawnUIInterface =  Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UMorrowBoneUIComponent* MorrowBoneUIComponent=PawnUIInterface->GetMorrowBoneUIComponentFromActor())
		{
			BP_GetMorrowBoneUIComponentAtInitialized(MorrowBoneUIComponent);
		}
	}
}
