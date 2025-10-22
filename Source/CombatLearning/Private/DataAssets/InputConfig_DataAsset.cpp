// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/InputConfig_DataAsset.h"

UInputAction* UInputConfig_DataAsset::FindInputActionInGameplayTag(const FGameplayTag& InInputTag)
{
	for (const FMorrowBoneInputMappingConfig& InputMappingConfig : NativeInputActions )
	{
		if (InputMappingConfig.InputTag==InInputTag && InputMappingConfig.InputAction)
		{
			return InputMappingConfig.InputAction;
		}
	}
	return nullptr;
}
