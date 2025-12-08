// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/InputConfig_DataAsset.h"


UInputAction* UInputConfig_DataAsset::FindInputActionInGameplayTag(const FGameplayTag& InInputTag)
{
	for (const auto& GameTag : NativeInputActions)
	{
		
		if (GameTag.InputTag==InInputTag)
		{
			return GameTag.InputAction;
		}
	}
	return nullptr;
}
