// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneClassBase.h"
#include "EnemyBase.generated.h"

class UWidgetComponent;
class UEnemyUIComponent;
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
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;

	//override ur PawnUI Interface Here
	virtual UPawnUIComponent* GetPawnUIComponent() const override;

	virtual UEnemyUIComponent* GetEnemyUIComponentFromActor() const override;
	
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="CombatComponent")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;

	//create ur Enemy UI Component
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="UIComponent")
	TObjectPtr<UEnemyUIComponent> EnemyUIComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Enemy | WidgetComponent")
	TObjectPtr<UWidgetComponent> EnemyHealthWidgetComponent;

	

	virtual void BeginPlay() override;
public:
	//have a seter and getter for our combat component
	UFUNCTION(BlueprintCallable,Category="Enemy|CombatComponent")
	 FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const
	{
		return EnemyCombatComponent;
	}

	UFUNCTION(BlueprintCallable,Category="Enemy|UIComponent")
	FORCEINLINE UEnemyUIComponent* GetEnemyUIComponent() const
	{
		return EnemyUIComponent;
	}
	

private:
	void AsynchronousLoadStartUpData();
};
