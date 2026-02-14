// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService/BTService_OrientToTarget.h"

UBTService_OrientToTarget::UBTService_OrientToTarget()
{
	NodeName = TEXT("Native Orient To Target");
	RotationInterpSpeed = 10.f;
	INIT_SERVICE_NODE_NOTIFY_FLAGS();
	//in ue 5.6 and further u hae to manually enable tick 
	bNotifyBecomeRelevant = true;
	bNotifyTick = true;
	Interval = 0.f;
	RandomDeviation = 0.f;
	InTargetKey.AddObjectFilter(this,GET_MEMBER_NAME_CHECKED(ThisClass,InTargetKey),AActor::StaticClass());
	
}

FString UBTService_OrientToTarget::GetStaticDescription() const
{
	const FString KeyName = InTargetKey.SelectedKeyName.ToString();
	return FString::Printf(TEXT("BT_Service Orient To Target key %s %s"), *KeyName,*GetStaticServiceDescription());
}


void UBTService_OrientToTarget::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	if (UBlackboardData* BlackboardData = GetBlackboardAsset())
	{
		InTargetKey.ResolveSelectedKey(*BlackboardData);
	}
}
