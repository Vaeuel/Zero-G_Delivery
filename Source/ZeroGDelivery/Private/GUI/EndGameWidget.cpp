// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/EndGameWidget.h"
#include "Components/TextBlock.h"

void UEndGameWidget::InitializeEndGameScreen(int32 CurrentScore, int32 PreviousScore)
{
    if (CurrentScoreText)
        CurrentScoreText->SetText(FText::FromString(FString::Printf(TEXT("Current Round Score: %d"), CurrentScore)));

    if (PreviousScoreText)
        PreviousScoreText->SetText(FText::FromString(FString::Printf(TEXT("Previous Round Score: %d"), PreviousScore)));
}