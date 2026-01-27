// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/MorrowBoneAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "MorrowBoneFunctionLibrary.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"


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

void UMorrowBoneAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	// this function executes after a Gameplay effect has been done  enemy / Self Attribute Set
 	Super::PostGameplayEffectExecute(Data);
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		// now lets set the values in the form of clamping
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(),0.0f,GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
	}
	// do the same thing for rage
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(),0.0f,GetMaxRage());
		SetCurrentRage(NewCurrentRage);
	}
	// Now use the proxy attribute to set the current health
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float Damage = GetDamageTaken();
		const float DamagedHealth=FMath::Clamp(GetCurrentHealth()-Damage,0.0f,GetMaxHealth());
		SetCurrentHealth(DamagedHealth);
	}
	if (GetCurrentHealth()<= 0 )
	{
		// u can add a gameplay tag to call a gameplay event to set the death Montages and everything
		//From the Data U can get the ASC of the current instance of calling of this function
		UMorrowBoneFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(),MorrowBoneGameplayTags::Shared_Status_Death);
		
	}

}
