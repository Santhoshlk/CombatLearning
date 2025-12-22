// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CombatLearning : ModuleRules
{
	public CombatLearning(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"GameplayTags",
			"GameplayTasks", "GameplayAbilities"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CombatLearning",
			"CombatLearning/Variant_Platforming",
			"CombatLearning/Variant_Platforming/Animation",
			"CombatLearning/Variant_Combat",
			"CombatLearning/Variant_Combat/AI",
			"CombatLearning/Variant_Combat/Animation",
			"CombatLearning/Variant_Combat/Gameplay",
			"CombatLearning/Variant_Combat/Interfaces",
			"CombatLearning/Variant_Combat/UI",
			"CombatLearning/Variant_SideScrolling",
			"CombatLearning/Variant_SideScrolling/AI",
			"CombatLearning/Variant_SideScrolling/Gameplay",
			"CombatLearning/Variant_SideScrolling/Interfaces",
			"CombatLearning/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
