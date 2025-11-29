// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneCharacterAnimInstance.h"
#include "MorrowBoneHeroAnimInstance.generated.h"

class AMorrowBone;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneHeroAnimInstance : public UMorrowBoneCharacterAnimInstance
{
	GENERATED_BODY()

public:
#pragma region Functions
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaTime) override;
#pragma endregion

	//to add the state of MorrowBone to its AnimInstance
	//U need a reference to the Character itself
#pragma region Components
     UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Character")
	  AMorrowBone* OwningPlayerCharacter;

#pragma endregion 


#pragma region Variables
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Anim data | Relax")
	bool bShouldEnterRelaxedState;

	//u should have some float one to see the threshold and one to calculate elapsed
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Anim Data | Relax")
	float EnterRelaxedStateThreshold=5.f;

	
	float IdleElapsedTime;
#pragma endregion
	
};
