// Copyright Epic Games, Inc. All Rights Reserved.

#include "SarumanGameMode.h"
#include "SarumanPlayerController.h"
#include "SarumanCharacter.h"
#include "SarumanPlayerState.h"
#include "UObject/ConstructorHelpers.h"

ASarumanGameMode::ASarumanGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASarumanPlayerController::StaticClass();
	PlayerStateClass = ASarumanPlayerState::StaticClass();
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}