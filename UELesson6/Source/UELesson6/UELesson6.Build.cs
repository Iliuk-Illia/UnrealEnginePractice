// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UELesson6 : ModuleRules
{
	public UELesson6(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
