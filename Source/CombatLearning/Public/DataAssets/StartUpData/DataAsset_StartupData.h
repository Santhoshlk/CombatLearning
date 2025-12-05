// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupData.generated.h"

class UMorrowBoneAbilitySystemComponent;
class UMorrowBoneGameplayAbility;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UDataAsset_StartupData : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToASC(TObjectPtr<UMorrowBoneAbilitySystemComponent> & ASC,int32 ApplyLevel=1);
private:
	void GrantAbility(TArray<TSubclassOf<UMorrowBoneGameplayAbility>> &InitialAbilities,TObjectPtr<UMorrowBoneAbilitySystemComponent> & ASC,int32 ApplyLevel=1);
protected:
	UPROPERTY(EditDefaultsOnly,Category="OnGiveAbility")
	TArray<TSubclassOf<UMorrowBoneGameplayAbility>> CommonStartupAbility;

	UPROPERTY(EditDefaultsOnly,Category="OnGiveAbility")
	TArray<TSubclassOf<UMorrowBoneGameplayAbility>> ReactiveAbility;
};
