// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/Hero/MorrowBoneHeroGameplayAbility.h"
#include "MBHeroGameplayAbility_TargetLock.generated.h"

class UMorrowBoneWidgetBase;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API UMBHeroGameplayAbility_TargetLock : public UMorrowBoneHeroGameplayAbility
{
	GENERATED_BODY()

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);
	
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

private:
	// now we are creating the actual Logic for lock on
	void TargetLockOn();

	void SetWidgetLocation();
	void GetAvailableTargets();

	void Cleanup();

	void CreateTargetLockWidget();

	void CancelTargetLock();
	
	
	AActor* GetNearestTarget( const TArray<AActor*> GetAvailableActors);
	
	

	UPROPERTY(EditDefaultsOnly,Category= "TargetLock")
	float TraceLength = 5000.f;

	UPROPERTY(EditDefaultsOnly,Category= "TargetLock")
	FVector TraceSize = FVector(5000.f,5000.f,500.f);

	UPROPERTY(EditDefaultsOnly ,Category= "TargetLock")
	 TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectType;
 
    UPROPERTY(EditDefaultsOnly, Category="TargetLockOn")
	bool isPersistentLinesOn = false;

	UPROPERTY()
	TArray<AActor*> TraceOutHitActors;

	

	UPROPERTY()
	AActor* CurrentTargetLockActor = nullptr;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"),Category="TargetLock | TargetLockWidget")
	TSubclassOf<UMorrowBoneWidgetBase> TargetLockWidgetClass;

	UPROPERTY()
	UMorrowBoneWidgetBase* TargetLockWidget = nullptr;
};
