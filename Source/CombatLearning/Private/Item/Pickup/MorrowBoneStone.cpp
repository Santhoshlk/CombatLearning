// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Pickup/MorrowBoneStone.h"

#include "CombatDebugHelper.h"
#include "NiagaraComponent.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "Character/MorrowBone.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"


// Sets default values
AMorrowBoneStone::AMorrowBoneStone()
{
	
	PrimaryActorTick.bCanEverTick = false;
	StoneNiagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("StoneMesh"));
	StoneNiagara->SetupAttachment(RootComponent);
}

void AMorrowBoneStone::PickupInteraction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (AMorrowBone* OverlappedHero = Cast<AMorrowBone>(OtherActor))
	{
		
		FGameplayTag InputTag = MorrowBoneGameplayTags::Player_Ability_Pickup_Stones;
		OverlappedHero->GetMorrowBoneAbilitySystemComponent()->TryActivateAbilitiesByTag(InputTag.GetSingleTagContainer());
	}
}



