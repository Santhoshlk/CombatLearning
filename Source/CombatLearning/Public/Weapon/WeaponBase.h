

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameFramework/Actor.h"
#include "WeaponStruct/WeaponStructTypes.h"
#include "WeaponBase.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

//declare a delegate so that it can take an AActor input and can be called from any class i.e. Combat Component
// all the logic of hit react  should be in combat component henceforth Combat component

DECLARE_DELEGATE_OneParam(FOnWeaponOverlapTarget,AActor*)

UCLASS()
class COMBATLEARNING_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AWeaponBase();

	FOnWeaponOverlapTarget WeaponHitTarget;
	FOnWeaponOverlapTarget WeaponPulledFromTarget;
	
protected:
#pragma region Components
	// we need a box collision and skeletal Mesh and maybe some scene Components
	UPROPERTY(EditDefaultsOnly, Category="Skeletal Mesh")
	 TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(EditDefaultsOnly, Category="BoxCollision")
	TObjectPtr<UBoxComponent> BoxCollision;

#pragma endregion

	
#pragma region variables
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="WeaponData")
	FWeaponData WeaponData;

private:
	UPROPERTY()
	TArray<FGameplayAbilitySpecHandle> OutGrantedMorrowBoneWeaponAbilitySpecHandle;
#pragma endregion

	
public:
	FORCEINLINE UBoxComponent* GetBoxCollision() const
	{
		return BoxCollision;
	}

	UFUNCTION(BlueprintCallable,Category="Weapon|WeaponData")
	void SetOutGrantedMorrowBoneWeaponAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle>&InGrantedMorrowBoneWeaponAbilitySpecHandle);

	UFUNCTION(BlueprintPure,Category="Weapon|WeaponData")
	TArray<FGameplayAbilitySpecHandle> GetOutGrantedMorrowBoneWeaponAbilitySpecHandle() const;

	UFUNCTION()
	virtual void WeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &  SweepResult);

	UFUNCTION()
	virtual void WeaponEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
