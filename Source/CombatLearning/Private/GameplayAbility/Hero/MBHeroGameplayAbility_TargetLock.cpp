// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Hero/MBHeroGameplayAbility_TargetLock.h"
#include "Character/MorrowBone.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/MorrowBoneWidgetBase.h"
#include "PlayerController/CombatClassPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "MorrowBoneFunctionLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetTree.h"
#include "Components/SizeBox.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTag/MorrowBoneGameplayTags.h"
#include "Kismet/KismetMathLibrary.h"



void UMBHeroGameplayAbility_TargetLock::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                                        const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                                        const FGameplayEventData* TriggerEventData)
{
	// u need to add the whole logic function in here
	TargetLockOn();
	SetTargetLockWalkSpeed();
	AddTargetSwitchIMC();
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
}

void UMBHeroGameplayAbility_TargetLock::EndAbility(const FGameplayAbilitySpecHandle Handle,
                                                   const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                                   bool bReplicateEndAbility, bool bWasCancelled)
{
	RemoveTargetSwitchIMC();
	ResetWalkSpeed();
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
	TraceOutHitActors.Empty();
 // Now this will refresh everything 
	
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

void UMBHeroGameplayAbility_TargetLock::TargetLockTickTask(float DeltaTime)
{
	if (!CurrentTargetLockActor || (UMorrowBoneFunctionLibrary::BP_DoesActorHaveTag(CurrentTargetLockActor,MorrowBoneGameplayTags::Shared_Status_Death))
		|| (UMorrowBoneFunctionLibrary::BP_DoesActorHaveTag(GetMorrowBoneCharacter(),MorrowBoneGameplayTags::Shared_Status_Death)))
		{
		   // u need to cancel the Task
		
		  CancelTargetLock();
		 return;
		}
	SetWidgetLocation();
	SetRotationToCurrentLockedActor(DeltaTime);
}

void UMBHeroGameplayAbility_TargetLock::SetRotationToCurrentLockedActor(float DeltaTime)
{
	bool bShouldInterpolate =true;

   if (UMorrowBoneFunctionLibrary::BP_DoesActorHaveTag(GetMorrowBoneCharacter(),MorrowBoneGameplayTags::Player_Status_Rolling) || UMorrowBoneFunctionLibrary::BP_DoesActorHaveTag(GetMorrowBoneCharacter(),MorrowBoneGameplayTags::Player_Status_Block))
   	{
   		bShouldInterpolate =false;
   	}
	

	if (bShouldInterpolate)
	{
		// now set the look at rotation and also for the camera
		const FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(GetMorrowBoneCharacter()->GetActorLocation(),CurrentTargetLockActor->GetActorLocation());
		const FRotator InterpRotation =FMath::RInterpTo(GetMorrowBonePlayerController()->GetControlRotation(),TargetRotation,DeltaTime,RotationInterpSpeed);

		  GetMorrowBonePlayerController()->SetControlRotation(FRotator(InterpRotation.Pitch,InterpRotation.Yaw,0.0));
		GetMorrowBoneCharacter()->SetActorRotation(FRotator(0.0,InterpRotation.Yaw,0.0));
	}

}

AActor* UMBHeroGameplayAbility_TargetLock::GetNearestTarget( TArray<AActor*>  AvailableActors)
{
	
	if (AvailableActors.IsEmpty())
	{
		return nullptr;
	}
	float MinDistance = 10000.f;
	AActor* NearestActor = nullptr;
	for (AActor*& HitActors : AvailableActors)
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

void UMBHeroGameplayAbility_TargetLock::SetTargetLockWalkSpeed()
{
	CachedWalkSpeed = GetMorrowBoneCharacter()->GetCharacterMovement()->GetMaxSpeed();
     GetMorrowBoneCharacter()->GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}

void UMBHeroGameplayAbility_TargetLock::ResetWalkSpeed()
{
	if (CachedWalkSpeed!=0.0f)
	{
		GetMorrowBoneCharacter()->GetCharacterMovement()->MaxWalkSpeed = CachedWalkSpeed;
	}
	
}

void UMBHeroGameplayAbility_TargetLock::SetSwitchTarget(const FGameplayTag& InInputTag)
{
   TArray<AActor*> LeftActors;
	TArray<AActor*> RightActors;
   AActor* NearestTarget = nullptr;
	SortIntoRightLeftTargets(LeftActors,RightActors);
	if (InInputTag.MatchesTagExact(MorrowBoneGameplayTags::Player_Event_SwitchTarget_Left))
	{
		
		NearestTarget = GetNearestTarget(LeftActors);
	}
	if (InInputTag.MatchesTagExact(MorrowBoneGameplayTags::Player_Event_SwitchTarget_Right))
	{
		NearestTarget = GetNearestTarget(RightActors);
	}

   if (NearestTarget)
   {
	   CurrentTargetLockActor = NearestTarget;
   }
	
}

void UMBHeroGameplayAbility_TargetLock::SortIntoRightLeftTargets(TArray<AActor*>& LeftActors,
	TArray<AActor*>& RightActors)
{
	LeftActors.Empty();
	RightActors.Empty();
	GetAvailableTargets();
   if (!CurrentTargetLockActor || TraceOutHitActors.IsEmpty() )
   {
   	
	   CancelTargetLock();
   	    return;
   }
   // start to sort them out
	const FVector PlayerToCurrentEnemyNorm = (CurrentTargetLockActor->GetActorLocation() - GetMorrowBoneCharacter()->GetActorLocation()).GetSafeNormal();
	for ( AActor* AvailableActors : TraceOutHitActors)
	{
		if (!AvailableActors || AvailableActors == CurrentTargetLockActor) continue;
      const FVector PlayerToEnemyNorm = (AvailableActors->GetActorLocation() - GetMorrowBoneCharacter()->GetActorLocation()).GetSafeNormal();
		const FVector Cross = FVector::CrossProduct(PlayerToEnemyNorm,PlayerToCurrentEnemyNorm);

		if (Cross.Z > 0.0f)
		{
			// left direction
			LeftActors.AddUnique(AvailableActors);
		}
		else
		{
			// Right Direction
			RightActors.AddUnique(AvailableActors);
		}
		
		
	}
	
}

void UMBHeroGameplayAbility_TargetLock::AddTargetSwitchIMC()
{
	 ULocalPlayer* LocalPlayer = GetMorrowBonePlayerController()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* SubSystem =ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	checkf(SubSystem,TEXT("Subsystem is not valid as Local player is not valid"));
     SubSystem->AddMappingContext(TargetIMC,1);
	
}

void UMBHeroGameplayAbility_TargetLock::RemoveTargetSwitchIMC()
{
	if (!GetMorrowBonePlayerController())
	{
		 return;
	}
	ULocalPlayer* LocalPlayer = GetMorrowBonePlayerController()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* SubSystem =ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	checkf(SubSystem,TEXT("Subsystem is not valid as Local player is not valid"));
	
	SubSystem->RemoveMappingContext(TargetIMC);
}


void UMBHeroGameplayAbility_TargetLock::Cleanup()
{
	
	
	
	TraceOutHitActors.Empty();
	CurrentTargetLockActor = nullptr;
	TargetLockWidget->RemoveFromParent();
	TargetLockWidget = nullptr;
	WidgetBoxSize = FVector2D::ZeroVector;
	if (CachedWalkSpeed!=0.f)
	{
		CachedWalkSpeed =0.f;
	}
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
