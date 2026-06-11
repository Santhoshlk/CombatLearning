#pragma once

UENUM()
enum class ECooldownActionsInput : uint8
{
	Start,
	Cancel
};

UENUM()
enum class ECooldownActionsOutput : uint8
{
	Updated,
	Completed,
	Canceled
};


