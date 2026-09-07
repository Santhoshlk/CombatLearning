// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FrontendUIFunctionLibrary.generated.h"

struct FGameplayTag;
class UWidget_ActivatableBase;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UFrontendUIFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure,Category="FrontendFunctionLibrary",meta=(Categories = "Frontend.Widget"))
	static TSoftClassPtr<UWidget_ActivatableBase> GetWidgetReferenceByTag(FGameplayTag InWidgetTag);
	
};
