// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Hero/MBHeroGameplayAbility_TargetLock.h"
#include "Character/MorrowBone.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/MorrowBoneWidgetBase.h"
#include "PlayerController/CombatClassPlayerController.h"
#include "CombatDebugHelper.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetTree.h"
#include "Components/SizeBox.h"


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
	Cleanup();
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UMBHeroGameplayAbility_TargetLock::TargetLockOn()
{
	// u can get the available target
	GetAvailableTargets();
	if (TraceOutHitActors.IsEmpty())
	{
		CancelTargetLock();
		return;
	}
	Debug::PrintMessage(TEXT("TargetLockOnActivated"));
	CurrentTargetLockActor = GetNearestTarget(TraceOutHitActors);
	if (CurrentTargetLockActor)
	{
		CreateTargetLockWidget();
		SetWidgetLocation();
	}
	else
	{
		  CancelTargetLock();
	}
	
	
}

void UMBHeroGameplayAbility_TargetLock::SetWidgetLocation()
{
	FVector2D ScreenPosition;
	UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(
		GetMorrowBonePlayerController(),
		 CurrentTargetLockActor->GetActorLocation(),
         ScreenPosition,
		 true
		);


	if (WidgetBoxSize == FVector2d::ZeroVector)
	{
		// u need to find the size of widget box
		TargetLockWidget->WidgetTree->ForEachWidget(
         [this](UWidget* TargetLockWidget)
         {
	        if (USizeBox* SizeBox = Cast<USizeBox>(TargetLockWidget)) 
	        {
		        WidgetBoxSize.X = SizeBox->GetWidthOverride();
	        	WidgetBoxSize.Y = SizeBox->GetHeightOverride();
	        }
         }
		);
		
	}
	ScreenPosition-=WidgetBoxSize/2.0;
	
	// u can Set tHe Screen Position of the Widget
	TargetLockWidget->SetPositionInViewport(ScreenPosition,false);
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



void UMBHeroGameplayAbility_TargetLock::CancelTargetLock()
{
	// if any lock goes wrong eliminate the Gameplay Ability Persistent State
	CancelAbility(GetCurrentAbilitySpecHandle(),GetCurrentActorInfo(),GetCurrentActivationInfo(),true);
	
}

AActor* UMBHeroGameplayAbility_TargetLock::GetNearestTarget(const TArray<AActor*> GetAvailableActors)
{
	float MinDistance = 10000.f;
	AActor* NearestActor = nullptr;
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
	
	return NearestActor;
}


void UMBHeroGameplayAbility_TargetLock::Cleanup()
{
	TraceOutHitActors.Empty();
	CurrentTargetLockActor = nullptr;
	TargetLockWidget->RemoveFromParent();
	TargetLockWidget = nullptr;
	WidgetBoxSize = FVector2D::ZeroVector;
}

void UMBHeroGameplayAbility_TargetLock::CreateTargetLockWidget()
{
	checkf(TargetLockWidgetClass,TEXT("u forgot to Assign the TSubClassOf for the Widget "));
	if (!TargetLockWidget)
	{

	
		TargetLockWidget = Cast<UMorrowBoneWidgetBase> (CreateWidget(GetMorrowBonePlayerController(),TargetLockWidgetClass));

		checkf(TargetLockWidget,TEXT("The Widget is Not Valid"));

		TargetLockWidget->AddToViewport();
	}
   
}
