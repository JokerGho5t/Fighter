// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Fighter : ModuleRules
{
	public Fighter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"HeadMountedDisplay",
			"AIModule",
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"InputCore",
			"EnhancedInput",
		});
	}
}
