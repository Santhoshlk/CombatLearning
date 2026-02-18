// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnUIComponent.h"
#include "MorrowBoneUIComponent.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponIconChangedDelegate,TSoftObjectPtr<UTexture2D>,Icon);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMBATLEARNING_API UMorrowBoneUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMorrowBoneUIComponent();	

	UPROPERTY(BlueprintAssignable, Category="MorrowBoneUIComponent")
	FonPercentageUpdatedDelegate CurrentRagePercentage;

	UPROPERTY(BlueprintCallable,BlueprintAssignable, Category="MorrowBoneUIComponent | Icon")
	FOnWeaponIconChangedDelegate OnWeaponIcon;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
