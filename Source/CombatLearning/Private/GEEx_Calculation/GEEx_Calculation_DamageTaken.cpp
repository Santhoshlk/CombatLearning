// Fill out your copyright notice in the Description page of Project Settings.


#include "GEEx_Calculation/GEEx_Calculation_DamageTaken.h"
#include "Attributes/MorrowBoneAttributeSet.h"

UGEEx_Calculation_DamageTaken::UGEEx_Calculation_DamageTaken()
{
	FProperty* AttackPowerProperty=FindFieldChecked<FProperty>(
		UMorrowBoneAttributeSet::StaticClass(),
		GET_MEMBER_NAME_CHECKED(UMorrowBoneAttributeSet,AttackPower));

	// now Create a GameplayEffectAttributeCaptureDefinition For it
	FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefinition(
		AttackPowerProperty,
		EGameplayEffectAttributeCaptureSource::Source,
		false);

	// then add this to relevant attributes to capture
	RelevantAttributesToCapture.Add(AttackPowerCaptureDefinition);
}
