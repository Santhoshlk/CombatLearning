// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/UI/PawnUIComponent.h"
#include "Widgets/MorrowBoneWidgetBase.h"

void UPawnUIComponent::RegisterDrawnWidgets(UMorrowBoneWidgetBase* Widget)
{
	if (Widget)
	{
		DrawnWidgets.AddUnique(Widget);
	}
	return;
}

void UPawnUIComponent::RemoveWidgets()
{
	if (DrawnWidgets.IsEmpty())
	{
		return;
	}

	for (auto& Widget : DrawnWidgets)
	{
		Widget->RemoveFromParent();
	}
	DrawnWidgets.Empty();
}
