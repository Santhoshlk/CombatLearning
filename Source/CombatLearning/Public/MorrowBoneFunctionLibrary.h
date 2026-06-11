// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MorrowBoneEnums.h"
#include "MorrowBoneFunctionLibrary.generated.h"

struct FGameplayEffectSpecHandle;
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

	UFUNCTION(BlueprintPure,Category="MorrowBoneFunctionLibrary|IsTargetPawnHostile")
	static bool IsTargetPawnHostile(APawn* AskingPawn,APawn* TargetPawn);

	UFUNCTION(BlueprintPure,Category="MorrowBoneFunctionLibrary|GetValueAt" , meta=(CompactNodeTitle = "Get Value At"))
	static float ScalableFloatAtLevel(const FScalableFloat& InputFloat,float Level)  ;

	UFUNCTION(BlueprintPure,Category="MorrowBoneFunctionLibrary|HitReactDirection")
	static FGameplayTag ComputeHitReactDirection(const AActor* InVictimActor , const  AActor* InAttackActor , float& OutDirectionalAngle);

	UFUNCTION(BlueprintPure,Category="MorrowBoneFunctionLibrary|BlockCheck")
	static bool ValidBlock(const AActor* InAttacker,AActor* InVictim);

	UFUNCTION(BlueprintCallable,Category = "MorrowBoneFunctionLibrary|ApplyGameplayEffectSpecHandleToTarget")
	static bool ApplyGameplayEffectSpecHandleToTarget(AActor* InSource,AActor* InTarget,const FGameplayEffectSpecHandle& SpecHandle);

	UFUNCTION(BlueprintCallable,Category="MorrowBoneFunctionLibrary|Cooldown" ,meta=(Latent,WorldContext = "WorldContextObject",LatentInfo = "LatentInfo",ExpandEnumAsExecs = "CooldownActionsInput|CooldownActionsOutput",TotalCooldownTime = "5",UpdateTimeAt = "0.1"))
	static void Cooldown(UObject* WorldContextObject,float TotalCooldownTime,float UpdateTimeAt,float& RemainingTime,ECooldownActionsInput CooldownActionsInput, UPARAM(DisplayName = "Output")ECooldownActionsOutput& CooldownActionsOutput,FLatentActionInfo LatentInfo);
};
