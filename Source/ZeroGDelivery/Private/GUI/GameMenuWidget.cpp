// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameMenuWidget.h"

void UGameMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateCargoIntegrity(1.0f);
	SetScoreText(0);
	SetTimerText(60);
	SetCargoScore(250); //Base Score 100 linked to integrity, 50 for prestine, and 100 for timely delivery (40Seconds to deliver and 5 points /second deducted for late fees?).
}

void UGameMenuWidget::UpdateCargoIntegrity(float IntegrityPercent)
{
	if (!CargoIntegrity) return;

	CargoIntegrity->SetPercent(IntegrityPercent);
}

void UGameMenuWidget::SetCargoScore(int FinalCargoScore)
{
	if (!CargoScore) return;

	UICargoScore += FinalCargoScore;
	CargoScore->SetText(FText::FromString(FString::Printf(TEXT("Cargo Score: %d"), UICargoScore)));
}

void UGameMenuWidget::SetScoreText(int TotalScore)
{
	if (!GameScore) return;

	UIScore += TotalScore;
	GameScore->SetText(FText::FromString(FString::Printf(TEXT("Current Score: %d"), UIScore)));
}

void UGameMenuWidget::SetTimerText(int Timer)
{
	if (!TimerText) return;

	UITimer += Timer;
	TimerText->SetText(FText::FromString(FString::Printf(TEXT("Time Left: %d"), UITimer)));
}
