// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "MorrowBoneGameplayAbility.generated.h"
class UPawnCombatComponent;

UENUM(BlueprintType)
enum class EMorrowBoneAbilityActivationPolicy : uint8
{
	onTriggered,
	onGiven
};
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMorrowBoneGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "ActivationPolicy")
	EMorrowBoneAbilityActivationPolicy ActivationPolicy = EMorrowBoneAbilityActivationPolicy::onTriggered;

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	
	//this bridges the Two classes so we can use Blueprint Pure
	UFUNCTION(BlueprintPure)
	UPawnCombatComponent* GetPawnCombatComponent() const
	{
		 return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
	}
};
