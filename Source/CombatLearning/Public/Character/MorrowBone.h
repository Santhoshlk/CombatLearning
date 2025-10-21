// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneClassBase.h"
#include "MorrowBone.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
/**
 * 
 */

UCLASS()
class COMBATLEARNING_API AMorrowBone : public AMorrowBoneClassBase
{
	GENERATED_BODY()
public:
	// u can still have Begin play even if u delete it from the base class it is a right of every unreal class
	virtual void BeginPlay() override;
	AMorrowBone();

	
private:
	//to divide into regions new trick by Vince Petrel
#pragma region component

	//now add all ur components in that region
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess="true"),Category="CameraBoom")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess="true"),Category="FollowCamera")
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY()
	TObjectPtr<UCapsuleComponent> Capsule;

	UPROPERTY()
	TObjectPtr<USkeletalMeshComponent> SkeletonMesh;
#pragma endregion 
};
