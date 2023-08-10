// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lesson7GameMode.h"
#include "Lesson7Character.h"
#include "UObject/ConstructorHelpers.h"

ALesson7GameMode::ALesson7GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
