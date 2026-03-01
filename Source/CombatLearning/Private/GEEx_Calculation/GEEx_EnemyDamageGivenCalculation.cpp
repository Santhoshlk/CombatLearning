// Fill out your copyright notice in the Description page of Project Settings.


#include "GEEx_Calculation/GEEx_EnemyDamageGivenCalculation.h"
#include "Attributes/MorrowBoneAttributeSet.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"
#include "GEEx_Calculation/GEEx_Calculation_DamageTaken.h"

struct FEnemyDamageAttributeCapture
{
	
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)
	FEnemyDamageAttributeCapture()
	{
		
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,AttackPower,Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,DefensePower,Target,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,DamageTaken,Target,false);
	}
};
// to prevent multiple declerations use static variable and a static function
static const FEnemyDamageAttributeCapture GetEnemyDamageAttributeCaptureDef() 
{
	static FEnemyDamageAttributeCapture DamageData;
	return DamageData;
	
}

UGEEx_EnemyDamageGivenCalculation::UGEEx_EnemyDamageGivenCalculation()
{
	RelevantAttributesToCapture.AddUnique(GetEnemyDamageAttributeCaptureDef().AttackPowerDef);
	RelevantAttributesToCapture.AddUnique(GetEnemyDamageAttributeCaptureDef().DefensePowerDef);
	RelevantAttributesToCapture.AddUnique(GetEnemyDamageAttributeCaptureDef().DamageTakenDef);
}

void UGEEx_EnemyDamageGivenCalculation::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

     const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	
	FAggregatorEvaluateParameters EvaluationParams;

	EvaluationParams.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluationParams.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float AttackPowerValue = 0.0f;
	float DefensePowerValue = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetEnemyDamageAttributeCaptureDef().AttackPowerDef,EvaluationParams,AttackPowerValue);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetEnemyDamageAttributeCaptureDef().DefensePowerDef,EvaluationParams,DefensePowerValue);
	float BaseWeaponDamageValue = 0.f;
	for (const TPair<FGameplayTag,float> TagMagnitudes :Spec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitudes.Key.MatchesTagExact(MorrowBoneGameplayTags::Enemy_SetByCaller_Melee))
		{
			BaseWeaponDamageValue = TagMagnitudes.Value;
		}
	}

	const float FinalDamage = BaseWeaponDamageValue * AttackPowerValue/DefensePowerValue;

	OutExecutionOutput.AddOutputModifier(
    FGameplayModifierEvaluatedData(
    	GetEnemyDamageAttributeCaptureDef().DamageTakenProperty,
    	EGameplayModOp::Override,
    	FinalDamage
    	)
	);
	
}
