// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/MorrowBoneAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "MorrowBoneFunctionLibrary.h"
#include "Components/UI/PawnUIComponent.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"
#include "Interface/PawnUIInterface.h"


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

	//Now what ur Going to Do is Bring the UI Component To PostGameplayEffect as the value of the UI Widget will be Given Here.
	 if (!CachedUIInterface.IsValid())
	 {
	 	//instead of using cast u can also use the Pointers
		 CachedUIInterface=TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	 }

    checkf(CachedUIInterface.IsValid(),TEXT(" %s The Actor Did not Implement the Interface Properly"),*Data.Target.GetAvatarActor()->GetActorNameOrLabel());
     UPawnUIComponent* PawnUIComponent= CachedUIInterface->GetPawnUIComponent();

	checkf(PawnUIComponent,TEXT("%s The Actor Did not Provide the UI Component"),*Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	
	
	// this function executes after a Gameplay effect has been done  enemy / Self Attribute Set
 	Super::PostGameplayEffectExecute(Data);
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		// now lets set the values in the form of clamping
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(),0.0f,GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
		PawnUIComponent->CurrentHealthPercentage.Broadcast(GetCurrentHealth()/GetMaxHealth());
	}
	// do the same thing for rage
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(),0.0f,GetMaxRage());
		SetCurrentRage(NewCurrentRage);

		//now as ur MorrowBone Character will have this but not enemy just don't do a check
		if (UMorrowBoneUIComponent*MorrowBoneUIComponent=CachedUIInterface->GetMorrowBoneUIComponentFromActor())
		{
			//call the broadcast
			MorrowBoneUIComponent->CurrentRagePercentage.Broadcast(GetCurrentRage()/GetMaxRage());
		}
	}
	// Now use the proxy attribute to set the current health
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float Damage = GetDamageTaken();
		const float DamagedHealth=FMath::Clamp(GetCurrentHealth()-Damage,0.0f,GetMaxHealth());
		SetCurrentHealth(DamagedHealth);
		PawnUIComponent->CurrentHealthPercentage.Broadcast(GetCurrentHealth()/GetMaxHealth());
		if (GetCurrentHealth()<= 0 )
		{
			// u can add a gameplay tag to call a gameplay event to set the death Montages and everything
			//From the Data U can get the ASC of the current instance of calling of this function
			UMorrowBoneFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(),MorrowBoneGameplayTags::Shared_Status_Death);
		
		}
	}
	

}
