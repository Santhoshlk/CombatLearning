// Fill out your copyright notice in the Description page of Project Settings.


#include "GEEx_Calculation/GEEx_Calculation_DamageTaken.h"
#include "StateTreeTypes.h"
#include "Attributes/MorrowBoneAttributeSet.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"
#include "CombatDebugHelper.h"


//create a struct for handling the declaration.

struct FMorrowBoneDamageDataCapture
{
	//first of all declare  them
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(CurrentStamina)
	DECLARE_ATTRIBUTE_CAPTUREDEF(MaxStamina)
	//declare the proxy Attribute to capture
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FMorrowBoneDamageDataCapture()
	{
		// now define them
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,AttackPower,Source,false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,DefensePower,Target,false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,CurrentStamina,Source,false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,MaxStamina,Source,false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMorrowBoneAttributeSet,DamageTaken,Target,false)
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
	RelevantAttributesToCapture.Add(GetMorrowBoneDamageDataCapture().CurrentStaminaDef);
	RelevantAttributesToCapture.Add(GetMorrowBoneDamageDataCapture().MaxStaminaDef);
	RelevantAttributesToCapture.Add(GetMorrowBoneDamageDataCapture().DamageTakenDef);
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

	float BaseWeaponDamage=0.0f;
	int32 UsedLightAttackComboCount=0;
	int32 UsedHeavyAttackComboCount=0;
	//use Spec to get ur Base Damage to weapon and combo count
	for (const auto& TagMagnitude :Spec.SetByCallerTagMagnitudes)
	{
		
		if (TagMagnitude.Key.MatchesTagExact(MorrowBoneGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseWeaponDamage=TagMagnitude.Value;
			// Debug::PrintDebugData(TEXT("BaseWeaponDamage"),BaseWeaponDamage);
		}

		if (TagMagnitude.Key.MatchesTagExact(MorrowBoneGameplayTags::Player_SetByCaller_AttackTypes_LightAttack))
		{
			UsedLightAttackComboCount=TagMagnitude.Value;
			// Debug::PrintDebugData(TEXT("UsedLightAttackComboCount"),UsedLightAttackComboCount);
		}

		if (TagMagnitude.Key.MatchesTagExact(MorrowBoneGameplayTags::Player_SetByCaller_AttackTypes_HeavyAttack))
		{
			UsedHeavyAttackComboCount=TagMagnitude.Value;
			// Debug::PrintDebugData(TEXT("UsedHeavyAttackComboCount"),UsedHeavyAttackComboCount);
		}
	}
	

	// u can use ur Execution Params to calculate the values  of all the parameters u need 
	float MorrowBoneAttackPower=0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMorrowBoneDamageDataCapture().AttackPowerDef,EvaluateParameters,MorrowBoneAttackPower);
	float EnemyDefensePower=0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMorrowBoneDamageDataCapture().DefensePowerDef,EvaluateParameters,EnemyDefensePower);
     float MorrowBoneCurrentStamina=0.0f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMorrowBoneDamageDataCapture().CurrentStaminaDef,EvaluateParameters,MorrowBoneCurrentStamina);
     float MorrowBoneMaxStamina=0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMorrowBoneDamageDataCapture().MaxStaminaDef,EvaluateParameters,MorrowBoneMaxStamina);
	// Debug::PrintDebugData(TEXT("MorrowBoneAttackPower"),MorrowBoneAttackPower);
	// Debug::PrintDebugData(TEXT("EnemyDefensePower"),EnemyDefensePower);
	//Damage Logic
	float Damage=BaseWeaponDamage;
	if (UsedLightAttackComboCount != 0)
	{
		// now write the multiplier 6% for the light attack
		const float LightAttackMultiplier = (UsedLightAttackComboCount-1)* 0.06 + 1.0f;
		Damage=BaseWeaponDamage* LightAttackMultiplier;
	}

	// Heavy Attack Logic
	if (UsedHeavyAttackComboCount != 0)
	{
		// this logic will be updated when 
		if (UsedHeavyAttackComboCount==2 || (UsedLightAttackComboCount==3 && UsedHeavyAttackComboCount==1))
		{
			// this is a direct power multiplier
			Damage=pow(BaseWeaponDamage,1.32);
		}
		else
		{
			const float HeavyAttackMultiplier = (UsedHeavyAttackComboCount)* 0.18 + 1.0f;
			Damage=BaseWeaponDamage*HeavyAttackMultiplier;
		}
	}

	// final weapon damage
	const float FinalDamage=Damage*(MorrowBoneAttackPower/EnemyDefensePower)*(1+0.12*(MorrowBoneCurrentStamina/MorrowBoneMaxStamina));
     Debug::PrintDebugData(TEXT("FinalDamage"),FinalDamage);
	//to Send Out The Final Damage u need a PlaceHolder Health Attribute U modify and then u modify health
	if (FinalDamage > 0.f)
	{
		// u don't need tro calculate the proxy Attribute
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetMorrowBoneDamageDataCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamage
				)
			);
	}
}
