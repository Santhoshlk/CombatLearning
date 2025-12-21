// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"
#include "WeaponStructTypes.generated.h"

class UInputMappingContext;
class UMorrowBoneGameplayAbility;
class UMorrowBoneLinkedAnimLayer;

// u include all the major required structs here
USTRUCT(BlueprintType)
struct FMorrowBoneAbilitySet
{
	GENERATED_BODY()

	//we need a place to store our gameplay abilities to give to our hero not on given and have tags
	// so we create a new struct as these are not the same abilities in the base class startup_data
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(Category="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UMorrowBoneGameplayAbility> HeroInputGameplayAbility;

	bool IsValid() const;
};
USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()
public:
	// we are using this to store our Linked Anim Layer and any other data weapon need
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="WeaponData")
	TSubclassOf<UMorrowBoneLinkedAnimLayer> WeaponAnimLayer;

	// the place where weapon stores all of its data
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,meta=(TitleProperty="InputTag"))
	TArray<FMorrowBoneAbilitySet> DefaultWeaponAbilities;

	//To store the bindings of these abilities InputMappingContext
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultWeaponInputMappingContext;
};