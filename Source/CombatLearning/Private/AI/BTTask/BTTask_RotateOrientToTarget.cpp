// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask/BTTask_RotateOrientToTarget.h"

#include "AIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "Kismet/KismetMathLibrary.h"

UBTTask_RotateOrientToTarget::UBTTask_RotateOrientToTarget()
{
	NodeName = TEXT("Native Rotate Orient To Target");
	AnglePrecision = 10.f;
	RotationInterpSpeed = 5.f;
	// to set up the tick 
	INIT_TASK_NODE_NOTIFY_FLAGS();

	// to actually make ticking && task work
	bNotifyTick = true;
	bNotifyTaskFinished = true;

	// set up the object filter
	// if you want to give names better is ThisClass
	InTargetKey.AddObjectFilter(this,GET_MEMBER_NAME_CHECKED(ThisClass,InTargetKey),AActor::StaticClass());
	
}

void UBTTask_RotateOrientToTarget::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	// if u have a key u need to resolve it
 if (UBlackboardData* BBData = GetBlackboardAsset())
 {
	 InTargetKey.ResolveSelectedKey(*BBData);
 }
	
}

uint16 UBTTask_RotateOrientToTarget::GetInstanceMemorySize() const
{
	// we need to give this so that the memory would allocate teh proper amount at the time of executing task
	return sizeof(FOnMemoryRotateOrientToTarget);
}

EBTNodeResult::Type UBTTask_RotateOrientToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UObject* TargetObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject(InTargetKey.SelectedKeyName);
	AActor* TargetActor = Cast<AActor>(TargetObject);
	APawn* OwningPawn = OwnerComp.GetAIOwner()->GetPawn();
	checkf(TargetActor && OwningPawn , TEXT("the Target Actor or the owning pawn is not valid "));
	FOnMemoryRotateOrientToTarget* Memory = CastInstanceNodeMemory<FOnMemoryRotateOrientToTarget>(NodeMemory);
	check(Memory);
	Memory->OwningPawn = OwningPawn;
	Memory->TargetActor = TargetActor;

	// even now the pointers are not valid the task has been failed
	if (!Memory->isValid())
	{
		return EBTNodeResult::Failed;
	}
    if (IsInAnglePrecision(Memory->OwningPawn.Get(),Memory->TargetActor.Get()))
    {
	    // now task has concluded call reset and finish the task
    	Memory->Reset();
    	return EBTNodeResult::Succeeded;
    }
   // now to do the actual work in tick 
	return EBTNodeResult::InProgress;
	
}

void UBTTask_RotateOrientToTarget::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// nothing in the base class
	// tick task comest after execute task so the memory value is obviously set
	// to finish task in tick use FinishLatentTask
	FOnMemoryRotateOrientToTarget* Memory = CastInstanceNodeMemory<FOnMemoryRotateOrientToTarget>(NodeMemory);
	check(Memory);
	if (!Memory->isValid())
	{
		FinishLatentTask(OwnerComp,EBTNodeResult::Failed);
	}
	else if (IsInAnglePrecision(Memory->OwningPawn.Get(),Memory->TargetActor.Get()))
	{
		// Task has succeeded
		Memory->Reset();
		FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
	}
	else
	{
		// now do the actual rotation
		//we change the rotation from owning pawn to target actor
		const FRotator FinalRotation = UKismetMathLibrary::FindLookAtRotation(Memory->OwningPawn->GetActorLocation(),Memory->TargetActor->GetActorLocation());
		FRotator InterpRotation = FMath::RInterpTo(Memory->OwningPawn->GetActorRotation(),FinalRotation,DeltaSeconds,RotationInterpSpeed);
		Memory->OwningPawn->SetActorRotation(InterpRotation);
		// whole interpolation process
	}
	
}

FString UBTTask_RotateOrientToTarget::GetStaticDescription() const
{
	const FString KeyName = InTargetKey.SelectedKeyName.ToString();
	return FString::Printf(TEXT("Rotate Orient to Face Target KeyName :  %s , Angle Precision : %s"),*KeyName,*FString::SanitizeFloat(AnglePrecision));
	 
}

bool UBTTask_RotateOrientToTarget::IsInAnglePrecision( const APawn* QueryPawn,const  AActor* TargetActor) const
{
	const FVector QueryToTarget = (TargetActor->GetActorLocation() - QueryPawn->GetActorLocation()).GetSafeNormal();
	float AngleToCheck = FVector::DotProduct(QueryToTarget,QueryPawn->GetActorForwardVector());
    // this will be in -1 to 1 so now change to degrees by taking cos inverse
     float Angle = UKismetMathLibrary::DegAcos(AngleToCheck);
	return Angle <= AnglePrecision;
}
