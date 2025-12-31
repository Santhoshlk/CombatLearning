// Fill out your copyright notice in the Description page of Project Settings.


#include "MorrowBoneFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"

UMorrowBoneAbilitySystemComponent* UMorrowBoneFunctionLibrary::NativeGetAbilitySystemComponentFromActor(AActor* InputActor)
{
	// first we need to check that if our actor is valid
	checkf(InputActor, TEXT("You Must provide a valid InputActor"));
	return CastChecked<UMorrowBoneAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InputActor));
}

void UMorrowBoneFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InputActor, FGameplayTag InInputTag)
{
	// first we need to check that if our actor is valid
	checkf(InputActor, TEXT("You Must provide a valid InputActor"));

	// now u need to add a new type of tag known as loose gameplay tag we are adding to actor as we are getting the asc through the actor
	UMorrowBoneAbilitySystemComponent*ASC=NativeGetAbilitySystemComponentFromActor(InputActor);
	if (!ASC->HasMatchingGameplayTag(InInputTag))
	{
		ASC->AddLooseGameplayTag(InInputTag);
	}
		
}

void UMorrowBoneFunctionLibrary::RemoveGameplayTagToActorIfFound(AActor* InputActor, FGameplayTag GameplayTagToRemove)
{
	// first we need to check that if our actor is valid
	checkf(InputActor, TEXT("You Must provide a valid InputActor"));

	// now u need to add a new type of tag known as loose gameplay tag we are adding to actor as we are getting the asc through the actor
	UMorrowBoneAbilitySystemComponent*ASC=NativeGetAbilitySystemComponentFromActor(InputActor);
	if (ASC->HasMatchingGameplayTag(GameplayTagToRemove))
	{
		ASC->RemoveLooseGameplayTag(GameplayTagToRemove);
	}
}

bool UMorrowBoneFunctionLibrary::NativeDoesActorHaveTag(AActor* InputActor, FGameplayTag InputTag)
{
	// first we need to check that if our actor is valid
	checkf(InputActor, TEXT("You Must provide a valid InputActor"));

	// now u need to add a new type of tag known as loose gameplay tag we are adding to actor as we are getting the asc through the actor
	UMorrowBoneAbilitySystemComponent*ASC=NativeGetAbilitySystemComponentFromActor(InputActor);

	return ASC->HasMatchingGameplayTag(InputTag);
}

bool UMorrowBoneFunctionLibrary::BP_DoesActorHaveTag(AActor* InputActor, FGameplayTag InputTag)
{
	return NativeDoesActorHaveTag(InputActor,InputTag);
}
