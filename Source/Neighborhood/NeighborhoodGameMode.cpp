// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NeighborhoodGameMode.h"
#include "NeighborhoodPawn.h"
#include "NeighborhoodHud.h"

ANeighborhoodGameMode::ANeighborhoodGameMode()
{
	DefaultPawnClass = ANeighborhoodPawn::StaticClass();
	HUDClass = ANeighborhoodHud::StaticClass();
}
