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
	TSubclassOf<UGameMenuWidget> StartingGameWidget;
	UGameMenuWidget* GameMenuWidgetContainer;

	void SpawnGameMenu(TSubclassOf<UGameMenuWidget> NewGameMenuWidget);
};
