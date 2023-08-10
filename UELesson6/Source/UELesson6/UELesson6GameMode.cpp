// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELesson6GameMode.h"
#include "UELesson6Character.h"
#include "UObject/ConstructorHelpers.h"

AUELesson6GameMode::AUELesson6GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
