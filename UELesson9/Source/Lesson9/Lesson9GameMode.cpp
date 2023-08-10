// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lesson9GameMode.h"
#include "Lesson9Character.h"
#include "UObject/ConstructorHelpers.h"

ALesson9GameMode::ALesson9GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
