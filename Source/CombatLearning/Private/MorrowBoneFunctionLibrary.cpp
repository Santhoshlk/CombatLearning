// Fill out your copyright notice in the Description page of Project Settings.


#include "MorrowBoneFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystem/MorrowBoneAbilitySystemComponent.h"
#include "GenericTeamAgentInterface.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"
#include "Interface/PawnCombatInterface.h"
#include "Kismet/KismetMathLibrary.h"


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

UPawnCombatComponent* UMorrowBoneFunctionLibrary::NativeGetCombatComponentFromActor(AActor* InputActor)
{
	checkf(InputActor,TEXT("The Input Actor Needs to be valid"))

	if(IPawnCombatInterface* PawnCombatInterface=Cast<IPawnCombatInterface>(InputActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}
	return nullptr;
}

UPawnCombatComponent* UMorrowBoneFunctionLibrary::BP_GetCombatComponentFromActor(AActor* InputActor)
{
	checkf(InputActor,TEXT("The Input Actor Needs to be valid"))
	return NativeGetCombatComponentFromActor(InputActor);
}

bool UMorrowBoneFunctionLibrary::IsTargetPawnHostile(APawn* AskingPawn, APawn* TargetPawn)
{
   checkf(AskingPawn && TargetPawn,TEXT("The Pawn u want to check are not valid"));
	IGenericTeamAgentInterface* AskingInterface = Cast<IGenericTeamAgentInterface>(AskingPawn->GetController());
	IGenericTeamAgentInterface* TargetInterface = Cast<IGenericTeamAgentInterface>(TargetPawn->GetController());
	if (TargetInterface && AskingInterface)
	{
		if (TargetInterface->GetGenericTeamId() != AskingInterface->GetGenericTeamId())
		{
			return true;
		}
	}
	return false;
}

float UMorrowBoneFunctionLibrary::ScalableFloatAtLevel(const FScalableFloat& InputFloat, float Level)  
{
	return InputFloat.GetValueAtLevel(Level);
}

FGameplayTag UMorrowBoneFunctionLibrary::ComputeHitReactDirection(const AActor* InVictimActor,const  AActor* InAttackActor,
	float& OutDirectionalAngle)
{
   checkf(InVictimActor && InAttackActor,TEXT("The victim or the Attacker Provided is not valid"));

	const FVector VictimForwardVector = InVictimActor->GetActorForwardVector();
	const FVector VictimToAttackerVector = (InAttackActor->GetActorLocation() - InVictimActor->GetActorLocation()).GetSafeNormal();
	float DotProduct =  FVector::DotProduct(VictimForwardVector,VictimToAttackerVector);
	OutDirectionalAngle = UKismetMathLibrary::DegAcos(DotProduct);
    const FVector CrossProduct = FVector::CrossProduct(VictimForwardVector,VictimToAttackerVector);

	if (CrossProduct.Z < 0.f)
	{
		OutDirectionalAngle*= -1;
	}

	 if (OutDirectionalAngle <= 45.f && OutDirectionalAngle >= -45.f)
    {
	    return MorrowBoneGameplayTags::Shared_Status_HitReact_Front;
    }
   if (OutDirectionalAngle >45.f && OutDirectionalAngle <=135.f)
   {
   	return MorrowBoneGameplayTags::Shared_Status_HitReact_Right;
   }
	if (OutDirectionalAngle < -45.f && OutDirectionalAngle >=-135.f)
	{
		return MorrowBoneGameplayTags::Shared_Status_HitReact_Left;
	}
	if ( (OutDirectionalAngle < -135 && OutDirectionalAngle >=-180) || (OutDirectionalAngle >135 && OutDirectionalAngle <=180))
	{
		return MorrowBoneGameplayTags::Shared_Status_HitReact_Back;
	}
	return FGameplayTag();
}

bool UMorrowBoneFunctionLibrary::ValidBlock(const AActor* InAttacker, AActor* InVictim)
{
   checkf(InAttacker && InVictim,TEXT("The Attacker and the victim actors should be valid"));
  const FVector AttackerFwd = InAttacker->GetActorForwardVector();
  const FVector VictimFwd = InVictim->GetActorForwardVector();

	double Angle =FVector::DotProduct(AttackerFwd,VictimFwd);
	
	if (Angle < 0.f)
	{
		return true;
	}
	
	return false;
	
}

bool UMorrowBoneFunctionLibrary::ApplyGameplayEffectSpecHandleToTarget(AActor* InSource, AActor* InTarget,
	const FGameplayEffectSpecHandle& SpecHandle)
{
	checkf(SpecHandle.IsValid() && InTarget && InSource,TEXT("The Source,Target,Spec Handle Should be valid"));
	UMorrowBoneAbilitySystemComponent* SourceASC =  NativeGetAbilitySystemComponentFromActor(InSource);
	UMorrowBoneAbilitySystemComponent* TargetASC =  NativeGetAbilitySystemComponentFromActor(InTarget);

	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = SourceASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data,TargetASC);

	if (ActiveGameplayEffectHandle.IsValid())
	{
		return ActiveGameplayEffectHandle.WasSuccessfullyApplied();
	}
	return false;
}
