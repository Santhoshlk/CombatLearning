#pragma once

UENUM(BlueprintType)
enum class EConformationScreenType : uint8
{
	Ok,
	YesNO,
	OkCancel,
	UnKnown UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EConformationScreenButtonType : uint8
{
	 // here three confirm cancel close
	 Confirm,
	Cancel,
	Close,
	Unknown UMETA(Hidden)	
};