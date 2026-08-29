// //  Lukka Kaushik Santhosh Combat and Common UI all rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Widgets/CommonUI/Widget_PrimaryWidgetLayout.h"
#include "FrontendUISubsystem.generated.h"

class UWidget_PrimaryWidgetLayout;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UFrontendUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	// the blueprint already has a getter for Subsystem so have one for c++
	static UFrontendUISubsystem* GetFrontendUISubsystem(const UObject* WorldContextObject);

protected:
    // ~ Begin USubsystem Interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	//~ End USubsystem Interface

	// now just add it
	UFUNCTION(BlueprintCallable)
	void RegisterPrimaryWidgetLayout( UWidget_PrimaryWidgetLayout* CreatedPrimaryWidgetLayout);
private:
	UPROPERTY(Transient)
	TObjectPtr<UWidget_PrimaryWidgetLayout> PrimaryWidgetLayout;
};
