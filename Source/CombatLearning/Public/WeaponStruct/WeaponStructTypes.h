// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "WeaponStructTypes.generated.h"

class UMorrowBoneLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()
public:
	// we are using this to store our Linked Anim Layer and any other data weapon need
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="WeaponData")
	TSubclassOf<UMorrowBoneLinkedAnimLayer> WeaponAnimLayer;
};