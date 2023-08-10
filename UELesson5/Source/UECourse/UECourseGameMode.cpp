// Copyright Epic Games, Inc. All Rights Reserved.

#include "UECourseGameMode.h"
#include "UECourseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUECourseGameMode::AUECourseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
