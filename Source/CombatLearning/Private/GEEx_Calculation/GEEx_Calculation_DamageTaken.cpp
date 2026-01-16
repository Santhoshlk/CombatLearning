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
