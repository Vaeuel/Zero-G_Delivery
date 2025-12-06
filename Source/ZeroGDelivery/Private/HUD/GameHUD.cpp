// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/GameHUD.h"
#include "Blueprint/UserWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("GameHUD: BeginPlay: BeginPlay creating widget..."));

	if (DeliveryHUDClass)
	{
		DeliveryHUD = CreateWidget<UGameMenuWidget>(GetWorld(), DeliveryHUDClass);
		if(!DeliveryHUD) UE_LOG(LogTemp, Error, TEXT("GameHUD: BeginPlay: FAILED to create widget!"));

		if (DeliveryHUD)
		{
			DeliveryHUD->AddToViewport();
			DeliveryHUD->SetVisibility(ESlateVisibility::Hidden); //Start hidden
		}
	}

	if(!DeliveryHUDClass) UE_LOG(LogTemp, Error, TEXT("GameHUD: BeginPlay: FAILED to create Delivery HUD Class"));
}

void AGameHUD::ToggleDeliveryHUD(bool bVisible)
{
	UE_LOG(LogTemp, Warning, TEXT("GameHUD: ToggleDeliveryHUD: ToggleDeliveryHUD called. Show = %d"), bVisible);

	if (!DeliveryHUD)
	{
		UE_LOG(LogTemp, Error, TEXT("GameHUD: ToggleDeliveryHUD: No widget container!"));
		return;
	}

	if (!DeliveryHUD) return;
	DeliveryHUD->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void AGameHUD::UpdateScore(int32 Score)
{
	if (DeliveryHUD)
		DeliveryHUD->SetScoreText(Score);
}

void AGameHUD::UpdateTimer(int32 TimeRemaining)
{
	if (DeliveryHUD)
		DeliveryHUD->SetTimerText(TimeRemaining);
}

void AGameHUD::UpdateContainerHealth(float HealthPercent)
{
	if (DeliveryHUD)
		DeliveryHUD->UpdateCargoIntegrity(HealthPercent);
}

void AGameHUD::AddCargoScore(int FinalCargoScore)
{
	if (DeliveryHUD)
		DeliveryHUD->SetCargoScore(FinalCargoScore);
}
