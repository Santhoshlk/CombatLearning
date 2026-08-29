// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "Widgets/CommonUI/Widget_PrimaryWidgetLayout.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryWidgetLayout::GetWidgetStack(const FGameplayTag InStackTag)
{
	checkf(InStackTag.IsValid(),TEXT("The Tag that u are giving is invalid"));

	checkf(WidgetStackMap.Contains(InStackTag),TEXT("The Stack that u are searching for does not exist"))

	return WidgetStackMap.FindRef(InStackTag);
}

void UWidget_PrimaryWidgetLayout::RegisterWidgetStacks(UPARAM(meta = (Categories = "Frontend.WidgetStack."))  FGameplayTag InStackTag,
                                                       UCommonActivatableWidgetContainerBase* const InStack)
{
	checkf(InStackTag.IsValid(),TEXT("The Tag that u are giving is invalid"));
		
	if (!IsDesignTime())
	{
		if (!WidgetStackMap.Contains(InStackTag))
		{
			  // u just add it
			WidgetStackMap.Emplace(InStackTag,InStack);
			
		}
	}
}
