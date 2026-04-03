// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Hero/MBHeroGameplayAbility_TargetLock.h"
#include "Character/MorrowBone.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CombatDebugHelper.h"
#include "DrawDebugHelpers.h"


void UMBHeroGameplayAbility_TargetLock::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                                        const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                                        const FGameplayEventData* TriggerEventData)
{
	// u need to add the whole logic function in here
	TargetLockOn();
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
}

void UMBHeroGameplayAbility_TargetLock::EndAbility(const FGameplayAbilitySpecHandle Handle,
                                                   const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                                   bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UMBHeroGameplayAbility_TargetLock::TargetLockOn()
{
	float MinDistance = 10000.f;
	AActor* NearestActor = nullptr;
	// u can get the available target
	GetAvailableTargets();
	for (AActor*& HitActors : TraceOutHitActors)
	{
		// now u find the nearest actor
		FVector DistanceVector = HitActors->GetActorLocation() - GetMorrowBoneCharacter()->GetActorLocation();
		float Distance =  DistanceVector.Size2D();
		if (Distance < MinDistance)
		{
			MinDistance = Distance;
			NearestActor = HitActors;
		}
	}
	Debug::PrintMessage(NearestActor->GetActorNameOrLabel());
    DrawDebugLine(GetWorld(),GetMorrowBoneCharacter()->GetActorLocation(),NearestActor->GetActorLocation(),FColor::Green,true); 
}

void UMBHeroGameplayAbility_TargetLock::GetAvailableTargets()
{
	// to get multiple targets u need to trace
	// so box trace Multiple objects
    const FVector EndTrace = GetMorrowBoneCharacter()->GetActorLocation() + GetMorrowBoneCharacter()->GetActorForwardVector()* TraceLength;
   TArray<FHitResult> TraceHitResults;
	
	UKismetSystemLibrary::BoxTraceMultiForObjects(
     GetMorrowBoneCharacter(),
     GetMorrowBoneCharacter()->GetActorLocation(),
     EndTrace,
     TraceSize/2.f,
     GetMorrowBoneCharacter()->GetActorForwardVector().ToOrientationRotator(),
     TraceObjectType,
     false,
     TArray<AActor*>(),
     isPersistentLinesOn ? EDrawDebugTrace::Persistent : EDrawDebugTrace::None,
     TraceHitResults,
     true
	);

	

   // now search it to have no self trace and store it
	for (const FHitResult& HitActors : TraceHitResults)
	{
		if ( AActor* HitActor = HitActors.GetActor())
		{
			if (HitActor != GetMorrowBoneCharacter())
			{
				TraceOutHitActors.AddUnique(HitActor);
			}
		}
	}
	
}
