// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/Hero/MorrowBoneHeroGameplayAbility.h"
#include "MBGameplayAbility_PickupStones.generated.h"

class AMorrowBoneStone;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMBGameplayAbility_PickupStones : public UMorrowBoneHeroGameplayAbility
{
	GENERATED_BODY()
protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

  UFUNCTION(BlueprintCallable)
	void CollectStone();

private:

	UPROPERTY(EditDefaultsOnly)
	float BoxTraceLength = 100.f;

	UPROPERTY(EditDefaultsOnly)
	FVector BoxTraceSize = FVector(100.f);

	UPROPERTY(EditDefaultsOnly)
	TArray<TEnumAsByte<	EObjectTypeQuery> > TraceObjectType;

	UPROPERTY(EditDefaultsOnly)
	bool bDrawDebugFrames;

	UPROPERTY()
	TArray<AMorrowBoneStone*> CollectedStones;
};
