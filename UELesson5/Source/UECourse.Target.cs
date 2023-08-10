// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UECourseTarget : TargetRules
{
	public UECourseTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("UECourse");
		
		// bOverrideBuildEnvironment = true;
        // AdditionalCompilerArguments = "-Wno-unused-but-set-variable";
	}
}
