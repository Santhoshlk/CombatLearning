 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnHelperComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATLEARNING_API UPawnHelperComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	//for template classes we generally use inline definition
	template<class T>
	T* GetOwningPawn() const 
	{
		static_assert(TPointerIsConvertibleFromTo<T,APawn>::Value,TEXT("The Pointer is only allowed to be cast from APawn and its SubClass"));
		return CastChecked<T>(GetOwner());
	}

	//for the default template class
	APawn* GetOwningPawn() const 
	{
		return CastChecked<APawn>(GetOwner());
	}
	template<class T>
	//here GetController<T> is a Type Definition which will take the pawns Controller and cast it to a Type T
	T* GetOwningController() const 
	{
		static_assert(TPointerIsConvertibleFromTo<T,APlayerController>::Value,TEXT("The Pointer is only allowed to be cast from APlayerController and its SubClass"));
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
