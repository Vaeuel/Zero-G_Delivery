// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/GameHUD.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	SpawnGameMenu(StartingGameWidget);
}

void AGameHUD::SpawnGameMenu(TSubclassOf<UGameMenuWidget> NewGameMenuWidget)
{
	if (GameMenuWidgetContainer)
	{
		GameMenuWidgetContainer->RemoveFromParent();
		GameMenuWidgetContainer = nullptr;
	}

	GameMenuWidgetContainer = CreateWidget<UGameMenuWidget>(GetWorld(), NewGameMenuWidget);
	GameMenuWidgetContainer->AddToViewport();
}
