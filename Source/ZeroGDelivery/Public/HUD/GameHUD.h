// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GUI/GameMenuWidget.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class ZEROGDELIVERY_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameMenuWidget> DeliveryHUDClass;
	UGameMenuWidget* DeliveryHUD;

	UFUNCTION()
	void ToggleDeliveryHUD(bool bVisible);

	UFUNCTION()
	void UpdateScore(int32 Score);

	UFUNCTION()
	void UpdateTimer(int32 TimeRemaining);

	UFUNCTION()
	void UpdateContainerHealth(float HealthPercent);

	UFUNCTION()
	void AddCargoScore(int FinalCargoScore);
};
