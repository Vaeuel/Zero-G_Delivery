// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/PauseMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GM_ZeroGDeliveryBase.h"

void UPauseMenuWidget::OnResumePressed()
{
	UWorld* World = GetWorld();
	if (!World) return;

	AGM_ZeroGDeliveryBase* GM = Cast<AGM_ZeroGDeliveryBase>(UGameplayStatics::GetGameMode(World));
	if (GM)
	{
		GM->TogglePauseMenu();
		return;
	}

	UGameplayStatics::SetGamePaused(World, false);
	APlayerController* PC = World->GetFirstPlayerController();
	if (PC)
	{
		PC->SetShowMouseCursor(false);
		PC->SetInputMode(FInputModeGameOnly());
	}
}

void UPauseMenuWidget::OnExitPressed()
{
	UWorld* World = GetWorld();
	if (!World) return;

	UGameplayStatics::SetGamePaused(World, false);

	UGameplayStatics::OpenLevel(World, FName("MainMenu"));
}