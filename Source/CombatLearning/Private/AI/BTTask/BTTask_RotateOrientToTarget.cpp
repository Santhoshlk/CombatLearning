// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask/BTTask_RotateOrientToTarget.h"

#include "BehaviorTree/BlackboardData.h"

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

FString UBTTask_RotateOrientToTarget::GetStaticDescription() const
{
	const FString KeyName = InTargetKey.SelectedKeyName.ToString();
	return FString::Printf(TEXT("Rotate Orient to Face Target KeyName :  %s , Angle Precision : %s"),*KeyName,*FString::SanitizeFloat(AnglePrecision));
	 
}
