// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved


#include "Subsystems/FrontendUISubsystem.h"

#include "CombatDebugHelper.h"

UFrontendUISubsystem* UFrontendUISubsystem::GetFrontendUISubsystem(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);
		// this won't let a nullptr

		return UGameInstance::GetSubsystem<UFrontendUISubsystem>(World->GetGameInstance());
	}
	return nullptr;
}

bool UFrontendUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
    if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
    {
    	TArray<UClass*> DerivedClasses;
	    GetDerivedClasses(GetClass(),DerivedClasses);
    	return DerivedClasses.IsEmpty();
    }
	
	return false;
}

void UFrontendUISubsystem::RegisterPrimaryWidgetLayout( UWidget_PrimaryWidgetLayout* CreatedPrimaryWidgetLayout)
{
	checkf(CreatedPrimaryWidgetLayout,TEXT("The Primary WidgetLayout should be valid"));

	PrimaryWidgetLayout = CreatedPrimaryWidgetLayout;

	if (PrimaryWidgetLayout)
	{
		Debug::PrintMessage("Primary Widget Layout Registered");
	}
}

