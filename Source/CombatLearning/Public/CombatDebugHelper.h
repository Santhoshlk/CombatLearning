
#pragma once

namespace Debug
{
	 static void PrintMessage(const FString &Msg,int key=1 ,FColor Colour=FColor::MakeRandomColor())
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(key,5.0f,Colour,Msg);
		}
	 	UE_LOG(LogTemp,Log,TEXT("%s"),*Msg)
	}
}