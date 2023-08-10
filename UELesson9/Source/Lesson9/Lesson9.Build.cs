// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Lesson9 : ModuleRules
{
	public Lesson9(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
