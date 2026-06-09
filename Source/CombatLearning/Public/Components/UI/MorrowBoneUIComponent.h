// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PawnUIComponent.h"
#include "MorrowBoneUIComponent.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponIconChangedDelegate,TSoftObjectPtr<UTexture2D>,Icon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FonAbilityIconUpdated,FGameplayTag,AbilityInputTag,TSoftObjectPtr<UMaterialInterface>,AbilityIconMaterialIntterface);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMBATLEARNING_API UMorrowBoneUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMorrowBoneUIComponent();	

	UPROPERTY(BlueprintAssignable, Category="MorrowBoneUIComponent")
	FonPercentageUpdatedDelegate CurrentRagePercentage;

	UPROPERTY(BlueprintCallable,BlueprintAssignable, Category="MorrowBoneUIComponent | Delegates")
	FOnWeaponIconChangedDelegate OnWeaponIcon;

	UPROPERTY(BlueprintCallable,BlueprintAssignable,Category="MorrowwBoneUIComponent | Delegates")
	FonAbilityIconUpdated LightAbilityIcon;

	UPROPERTY(BlueprintCallable,BlueprintAssignable,Category="MorrowwBoneUIComponent | Delegates")
	FonAbilityIconUpdated HeavyAbilityIcon;


};
