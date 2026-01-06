// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "MorrowBoneAttributeSet.generated.h"
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
  
 	
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UMorrowBoneAttributeSet();

protected:

	//now write attribute accessor to make these functions
	UPROPERTY(BlueprintReadOnly,Category="Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,CurrentHealth)

	UPROPERTY(BlueprintReadOnly,Category="Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,MaxHealth)

	UPROPERTY(BlueprintReadOnly,Category="Rage")
	FGameplayAttributeData CurrentRage;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,CurrentRage)

	UPROPERTY(BlueprintReadOnly,Category="Rage")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,MaxRage)

	UPROPERTY(BlueprintReadOnly,Category="AP")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,AttackPower)

	UPROPERTY(BlueprintReadOnly,Category="DP")
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,DefensePower)

	UPROPERTY(BlueprintReadOnly,Category="Stamina")
	FGameplayAttributeData  CurrentStamina;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,CurrentStamina)

	UPROPERTY(BlueprintReadOnly,Category="Stamina")
	FGameplayAttributeData  MaxStamina;
	ATTRIBUTE_ACCESSORS(UMorrowBoneAttributeSet,MaxStamina)
};
