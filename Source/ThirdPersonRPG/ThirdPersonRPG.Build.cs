// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ThirdPersonRPG : ModuleRules
{
	public ThirdPersonRPG(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ThirdPersonRPG",
			"ThirdPersonRPG/Variant_Platforming",
			"ThirdPersonRPG/Variant_Platforming/Animation",
			"ThirdPersonRPG/Variant_Combat",
			"ThirdPersonRPG/Variant_Combat/AI",
			"ThirdPersonRPG/Variant_Combat/Animation",
			"ThirdPersonRPG/Variant_Combat/Gameplay",
			"ThirdPersonRPG/Variant_Combat/Interfaces",
			"ThirdPersonRPG/Variant_Combat/UI",
			"ThirdPersonRPG/Variant_SideScrolling",
			"ThirdPersonRPG/Variant_SideScrolling/AI",
			"ThirdPersonRPG/Variant_SideScrolling/Gameplay",
			"ThirdPersonRPG/Variant_SideScrolling/Interfaces",
			"ThirdPersonRPG/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
