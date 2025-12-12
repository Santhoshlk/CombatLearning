// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/InputConfig_DataAsset.h"
#include "MorrowBoneInputComponent.generated.h"




UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMBATLEARNING_API UMorrowBoneInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	template<class UserObject,typename CallBackFunc>
	void BindingInputs( TObjectPtr<UInputConfig_DataAsset> &InInputConfig,const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UserObject* ContextObject,CallBackFunc Func);

	// u need a new template class to have the logic for AbilityInput Bindings
	template<class  UserObject,typename CallBackFunc>
	void AbilityBindingInputs(TObjectPtr<UInputConfig_DataAsset> &InInputConfig,UserObject object,CallBackFunc StartedFunc,CallBackFunc ReleasedFunc);


};

template <class UserObject, typename CallBackFunc>
void UMorrowBoneInputComponent::BindingInputs(TObjectPtr<UInputConfig_DataAsset>& InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunc Func)
{
	//to check the Input Config
	checkf(InInputConfig,TEXT("U did not provide the valid Asset"));
	if (UInputAction* FoundAction=InInputConfig->FindInputActionInGameplayTag(InInputTag))
	{
		//so we are checking the search function and then we are binding The InputAction
		BindAction(FoundAction,TriggerEvent,ContextObject,Func);
	}
}

template <class UserObject, typename CallBackFunc>
void UMorrowBoneInputComponent::AbilityBindingInputs(TObjectPtr<UInputConfig_DataAsset>& InInputConfig,
	UserObject object, CallBackFunc StartedFunc, CallBackFunc ReleasedFunc)
{
	// first of all u need to check the Data Asset
	checkf(InInputConfig,TEXT("The Data Asset which u have provided is Not Valid"))

	for (const auto& InputAbilityAction : InInputConfig->AbilityInputActions)
	{
		// always if you are adding a value in TArrays or using it check the nullptr;
		if (!InputAbilityAction.IsValid()) continue;
		BindAction(InputAbilityAction.InputAction,ETriggerEvent::Started,object,StartedFunc);
		BindAction(InputAbilityAction.InputAction,ETriggerEvent::Completed,object,ReleasedFunc);
	}
}
