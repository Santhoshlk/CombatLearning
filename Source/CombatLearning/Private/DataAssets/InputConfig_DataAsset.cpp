// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/InputConfig_DataAsset.h"


UInputAction* UInputConfig_DataAsset::FindInputActionInGameplayTag(const FGameplayTag& InInputTag)
{
	// this is only for Native Inputs
	for (const FMorrowBoneInputMappingConfig& CurrentInputActions : NativeInputActions)
	{
		if (!CurrentInputActions.IsValid()) continue;
		if (CurrentInputActions.InputTag == InInputTag)
		{
			return CurrentInputActions.InputAction;
		}
	}
	return nullptr;
}
