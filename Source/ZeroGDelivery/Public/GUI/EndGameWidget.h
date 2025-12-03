// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZEROGDELIVERY_API UEndGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    void InitializeEndGameScreen(int32 CurrentScore, int32 PreviousScore);

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* CurrentScoreText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* PreviousScoreText;
};
