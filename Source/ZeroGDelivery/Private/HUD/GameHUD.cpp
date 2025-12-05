// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/GameHUD.h"
#include "Blueprint/UserWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (DeliveryHUDClass)
	{
		DeliveryHUD = CreateWidget<UGameMenuWidget>(GetWorld(), DeliveryHUDClass);
		if (DeliveryHUD)
		{
			DeliveryHUD->AddToViewport();
			DeliveryHUD->SetVisibility(ESlateVisibility::Hidden); //Start hidden
		}
	}
}

void AGameHUD::ToggleDeliveryHUD(bool bVisible)
{
	if (!DeliveryHUD) return;
	DeliveryHUD->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void AGameHUD::UpdateScore(int32 Score)
{
	if (DeliveryHUD)
		DeliveryHUD->SetScoreText(Score);
}

void AGameHUD::UpdateTimer(float TimeRemaining)
{
	if (DeliveryHUD)
		DeliveryHUD->SetTimerText(TimeRemaining);
}

void AGameHUD::UpdateContainerHealth(int32 HealthPercent)
{
	if (DeliveryHUD)
		DeliveryHUD->UpdateCargoIntegrity(HealthPercent);
}

void AGameHUD::AddCargoScore(int FinalCargoScore)
{
	if (DeliveryHUD)
		DeliveryHUD->SetCargoScore(FinalCargoScore);
}
