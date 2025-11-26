// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "GUI/ButtonWidget.h"
#include "GameMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZEROGDELIVERY_API UGameMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* CargoIntegrity;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* IntegrityText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TimerText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CargoScore;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* GameScore;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* ButtonContainer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> ButtonWidgetClass;

	UFUNCTION()
	void UpdateCargoIntegrity(float IntegrityPercent);

	UFUNCTION()
	void SetCargoScore(int FinalCargoScore);

	UFUNCTION()
	void SetScoreText(int TotalScore);

	UFUNCTION()
	void SetTimerText(int Timer);

private:
	int UIScore;
	int UITimer;
	int UICargoScore;
};
