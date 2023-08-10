// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELesson4GameMode.h"
#include "UELesson4Character.h"
#include "UObject/ConstructorHelpers.h"

AUELesson4GameMode::AUELesson4GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
