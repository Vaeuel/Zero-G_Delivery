// Fill out your copyright notice in the Description page of Project Settings.

#include "GM_MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void AGM_MainMenu::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (!World) return;

	APlayerController* PC = World->GetFirstPlayerController();
	if (!PC) return;

	PC->SetShowMouseCursor(true);
	PC->SetInputMode(FInputModeUIOnly());

	if (MainMenuClass)
	{
		MainMenuInstance = CreateWidget<UUserWidget>(PC, MainMenuClass);
		if (MainMenuInstance)
		{
			MainMenuInstance->AddToViewport();
		}
	}
}