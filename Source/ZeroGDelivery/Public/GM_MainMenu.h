// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "GM_MainMenu.generated.h"

UCLASS()
class ZEROGDELIVERY_API AGM_MainMenu : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	// Assign in editor (WBP_MainMenu)
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> MainMenuClass;

private:
	UPROPERTY()
	UUserWidget* MainMenuInstance = nullptr;
};