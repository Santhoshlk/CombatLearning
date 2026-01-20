// Fill out your copyright notice in the Description page of Project Settings.


#include "GEEx_Calculation/GEEx_Calculation_DamageTaken.h"
#include "Attributes/MorrowBoneAttributeSet.h"

//create a struct for handling the declaration.

struct FMorrowBoneDamageDataCapture
{
	//first of all declare  them
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)

	FMorrowBoneDamageDataCapture()
	{
		// now define them
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,AttackPower,Source,false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,DefensePower,Source,false)
	}
};

// create a static func and variable definition as the values need to be captured only once
static const FMorrowBoneDamageDataCapture& GetMorrowBoneDamageDataCapture()
{
	static FMorrowBoneDamageDataCapture Data;
	return Data;
}
UGEEx_Calculation_DamageTaken::UGEEx_Calculation_DamageTaken()
{
	// add this to relevant attributes to capture
	RelevantAttributesToCapture.Add(GetMorrowBoneDamageDataCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetMorrowBoneDamageDataCapture().DefensePowerDef);
	
}

void UGEEx_Calculation_DamageTaken::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
   
	
	
	// create get in runtime owning spec Handle
	const FGameplayEffectSpec& Spec=ExecutionParams.GetOwningSpec();

	// u can also get the  context handle
	// Spec.GetContext().GetSourceObject()
	// Spec.GetContext().GetInstigator()
	// Spec.GetContext().GetAbility()
	// Spec.GetContext().GetEffectCauser()
	//create ur aggregate Evaluate Params
	FAggregatorEvaluateParameters EvaluateParameters;
	//set the source and target tags
	EvaluateParameters.SourceTags=Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags=Spec.CapturedTargetTags.GetAggregatedTags();

	// u can use ur Execution Params to calculate the values
	float MorrowBoneAttackPower=0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMorrowBoneDamageDataCapture().AttackPowerDef,EvaluateParameters,MorrowBoneAttackPower);
	float MorrowBoneDefensePower=0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMorrowBoneDamageDataCapture().DefensePowerDef,EvaluateParameters,MorrowBoneDefensePower);
}
