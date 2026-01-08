// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MorrowBoneFunctionLibrary.generated.h"

class UPawnCombatComponent;
class UMorrowBoneAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// this is a library which we can use anywhere
	static UMorrowBoneAbilitySystemComponent* NativeGetAbilitySystemComponentFromActor(AActor* InputActor);

	UFUNCTION(BlueprintCallable,Category="MorrowBone|MorrowBoneFunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InputActor,FGameplayTag InInputTag);

	UFUNCTION(BlueprintCallable,Category="MorrowBone|MorrowBoneFunctionLibrary")
	static void RemoveGameplayTagToActorIfFound(AActor* InputActor,FGameplayTag GameplayTagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InputActor,FGameplayTag InputTag);

	UFUNCTION(BlueprintCallable,Category="MorrowBone|MorrowBoneFunctionLibrary",meta=(DisplayName="DoesActorHaveTag"))
	static bool BP_DoesActorHaveTag(AActor* InputActor,FGameplayTag InputTag);

	static UPawnCombatComponent* NativeGetCombatComponentFromActor(AActor* InputActor);

	UFUNCTION(BlueprintCallable,Category="MorrowBoneFunctionLibrary|CombatComponent",meta=(DisplayName="GetCombatComponentFromActor"))
	static UPawnCombatComponent* BP_GetCombatComponentFromActor(AActor* InputActor);
};
