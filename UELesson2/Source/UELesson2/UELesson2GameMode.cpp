// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELesson2GameMode.h"
#include "UELesson2Character.h"
#include "UObject/ConstructorHelpers.h"

AUELesson2GameMode::AUELesson2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
