// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Hero/MBGameplayAbility_PickupStones.h"

#include "CombatDebugHelper.h"
#include "Character/MorrowBone.h"
#include "Item/Pickup/MorrowBoneStone.h"
#include "Kismet/KismetSystemLibrary.h"

void UMBGameplayAbility_PickupStones::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                                      const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                                      const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UMBGameplayAbility_PickupStones::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UMBGameplayAbility_PickupStones::CollectStone()
{
 // we need to empty out colleted stone for the trace to be not bad
	CollectedStones.Empty();
	
   TArray<FHitResult> CollectedActors;
	
	const FVector BoxTraceEnd = GetMorrowBoneCharacter()->GetActorUpVector()*-1.f*BoxTraceLength;
	UKismetSystemLibrary::BoxTraceMultiForObjects(GetMorrowBoneCharacter(),
     GetMorrowBoneCharacter()->GetActorLocation(),
     BoxTraceEnd,
     BoxTraceSize/2.f,
     (-GetMorrowBoneCharacter()->GetActorUpVector()).ToOrientationRotator(),
     TraceObjectType,
     false,
     TArray<AActor*>(),
     bDrawDebugFrames ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
     CollectedActors,
     true
	);

	// cast to check the stones
    for (const auto& CollectedActor  : CollectedActors)
    {
	    if (AMorrowBoneStone* CurrentStone = Cast<AMorrowBoneStone>(CollectedActor.GetActor()))
	    {
	    	
		    CollectedStones.AddUnique(CurrentStone);
	    }
    }

	if (CollectedStones.IsEmpty())
	{
		CancelAbility(GetCurrentAbilitySpecHandle(),GetCurrentActorInfo(),GetCurrentActivationInfo(),true);
	}
	
}
