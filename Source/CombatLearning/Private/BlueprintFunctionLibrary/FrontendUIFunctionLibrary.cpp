// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "BlueprintFunctionLibrary/FrontendUIFunctionLibrary.h"

#include "DeveloperSettings/FrontendUIDeveloperSettings.h"

TSoftClassPtr<UWidget_ActivatableBase> UFrontendUIFunctionLibrary::GetWidgetReferenceByTag(FGameplayTag InWidgetTag)
{
   const UFrontendUIDeveloperSettings* DeveloperSettings =	GetDefault<UFrontendUIDeveloperSettings>();
   checkf(InWidgetTag.IsValid() && DeveloperSettings ,TEXT("The Tag and Settings Should be Valid"));

   checkf(DeveloperSettings->WidgetReferenceMap.Contains(InWidgetTag),TEXT("The Widget Reference is not found"))

   return DeveloperSettings->WidgetReferenceMap.FindRef(InWidgetTag);
}
