// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenuWidget::OnStartGamePressed()
{
	UWorld* World = GetWorld();
	if (!World) return;

	APlayerController* PC = World->GetFirstPlayerController();
	if (PC)
	{
		PC->SetShowMouseCursor(false);
		PC->SetInputMode(FInputModeGameOnly());
	}

	UGameplayStatics::OpenLevel(World, FName("GameMap"));
}

void UMainMenuWidget::OnQuitGamePressed()
{
	UWorld* World = GetWorld();
	if (!World) return;

	// Clean exit for packaged builds & PIE
	UKismetSystemLibrary::QuitGame(
		World,
		World->GetFirstPlayerController(),
		EQuitPreference::Quit,
		false
	);
}