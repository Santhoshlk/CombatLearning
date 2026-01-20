
#pragma once

namespace Debug
{
	 static void PrintMessage(const FString &Msg,int key=-1 ,FColor Color=FColor::MakeRandomColor())
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(key,5.0f,Color,Msg);
		}
	 	UE_LOG(LogTemp,Log,TEXT("%s"),*Msg)
	}

	static void PrintDebugData(const FString &Msg, float FloatToPrint,int key=-1 ,FColor Color=FColor::MakeRandomColor())
	 {
		 if (GEngine)
		 {
		 	const FString FinalMessage=Msg + TEXT(":") + FString::SanitizeFloat(FloatToPrint);
			 GEngine->AddOnScreenDebugMessage(key,5.f,Color,FinalMessage);

		 	UE_LOG(LogTemp,Warning,TEXT("%s"),*FinalMessage)
		 }
	 }
}