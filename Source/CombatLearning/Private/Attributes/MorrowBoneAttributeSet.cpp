// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/MorrowBoneAttributeSet.h"

UMorrowBoneAttributeSet::UMorrowBoneAttributeSet()
{
	InitCurrentHealth(1.0F);
	InitMaxHealth(10.0F);
	InitCurrentRage(1.0f);
	InitMaxRage(10.0f);
	InitCurrentStamina(1.0f);
	InitMaxStamina(10.0f);
	InitAttackPower(15.0f);
	InitDefensePower(15.0f);
}
