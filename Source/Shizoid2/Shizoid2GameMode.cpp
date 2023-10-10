// Copyright Epic Games, Inc. All Rights Reserved.

#include "Shizoid2GameMode.h"
#include "Shizoid2Character.h"
#include "ShizoidController.h"
#include "UObject/ConstructorHelpers.h"

AShizoid2GameMode::AShizoid2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
