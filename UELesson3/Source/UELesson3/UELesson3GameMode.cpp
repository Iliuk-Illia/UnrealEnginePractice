// Copyright Epic Games, Inc. All Rights Reserved.

#include "UELesson3GameMode.h"
#include "UELesson3Character.h"
#include "UObject/ConstructorHelpers.h"

AUELesson3GameMode::AUELesson3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
