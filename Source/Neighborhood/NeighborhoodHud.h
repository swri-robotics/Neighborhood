// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "NeighborhoodHud.generated.h"


UCLASS(config = Game)
class ANeighborhoodHud : public AHUD
{
	GENERATED_BODY()

public:
	ANeighborhoodHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
