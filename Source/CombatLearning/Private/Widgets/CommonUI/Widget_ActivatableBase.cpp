// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "Widgets/CommonUI/Widget_ActivatableBase.h"
#include "PlayerController/CombatClassPlayerController.h"

ACombatClassPlayerController* UWidget_ActivatableBase::GetOwningPlayerController()
{
	if (!CachedPlayerController.IsValid())
	{
		CachedPlayerController = GetOwningPlayer<ACombatClassPlayerController>();
		return CachedPlayerController.Get();
	}
	return CachedPlayerController.Get();
}
