// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "FrontendUIDeveloperSettings.generated.h"

class UWidget_ActivatableBase;
/**
 * 
 */
UCLASS(Config = Game,DefaultConfig,meta=(DisplayName = "FrontendUISettings"))
class COMBATLEARNING_API UFrontendUIDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:

	UPROPERTY(Config,EditDefaultsOnly,Category="WidgetReferences",meta=(ForceInlineRow	,Categories = "Frontend.Widget.") )
	TMap<FGameplayTag,TSoftClassPtr<UWidget_ActivatableBase>> WidgetReferenceMap;
};
