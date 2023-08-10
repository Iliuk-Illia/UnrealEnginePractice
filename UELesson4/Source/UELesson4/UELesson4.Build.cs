// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UELesson4 : ModuleRules
{
	public UELesson4(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
