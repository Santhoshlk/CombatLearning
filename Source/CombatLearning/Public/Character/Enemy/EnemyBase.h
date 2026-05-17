// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/MorrowBoneClassBase.h"
#include "EnemyBase.generated.h"


class UWidgetComponent;
class UEnemyUIComponent;
class UEnemyCombatComponent;
class UBoxComponent;
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

	UPROPERTY(VisibleAnywhere,Category = "Enemy | Melee")
	TObjectPtr<UBoxComponent> LeftHandCollisionBox;

	UPROPERTY(VisibleAnywhere,Category = "Enemy | Melee")
	TObjectPtr<UBoxComponent> RightHandCollisionBox;

	UPROPERTY(EditDefaultsOnly,Category = "Enemy | CollisionBox")
	FName LeftCollisionBox;

	UPROPERTY(EditDefaultsOnly,Category = "Enemy | CollisionBox")
	FName RightCollisionBox;
	
	
	virtual void BeginPlay() override;

  UFUNCTION()
 virtual void OnCollisionBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

#if WITH_EDITOR
	virtual void PostEditChangeProperty( struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif	
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
	
	UFUNCTION(BlueprintCallable,Category="Enemy|CombatComponent")
	FORCEINLINE UBoxComponent* GetLeftBoxCollision() const
	{
		return LeftHandCollisionBox;
	}

	UFUNCTION(BlueprintCallable,Category="Enemy|CombatComponent")
	FORCEINLINE UBoxComponent* GetRightBoxCollision() const
	{
		return RightHandCollisionBox ;
	}


	
private:
	void AsynchronousLoadStartUpData();
};
