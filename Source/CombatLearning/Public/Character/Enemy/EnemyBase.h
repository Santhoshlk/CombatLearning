// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneClassBase.h"
#include "EnemyBase.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class COMBATLEARNING_API AEnemyBase : public AMorrowBoneClassBase
{
	GENERATED_BODY()
public:
	AEnemyBase();
	
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="CombatComponent")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;

	virtual void BeginPlay() override;
public:
	//have a seter and getter for our combat component
	UFUNCTION(BlueprintCallable,Category="Enemy|CombatComponent")
	 FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const
	{
		return EnemyCombatComponent;
	}

private:
	void AsynchronousLoadStartUpData();
};
