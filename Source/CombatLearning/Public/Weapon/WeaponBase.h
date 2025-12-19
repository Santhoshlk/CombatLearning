

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponStruct/WeaponStructTypes.h"
#include "WeaponBase.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
UCLASS()
class COMBATLEARNING_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AWeaponBase();
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
#pragma endregion

	
public:
	FORCEINLINE UBoxComponent* GetBoxCollision() const
	{
		return BoxCollision;
	}
};
