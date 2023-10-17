// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Shizoid2 : ModuleRules
{
	public Shizoid2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities",  "GameplayTags", "GameplayTasks", "UMG", "ModularGameplay", "GameFeatures" });
	}
}
