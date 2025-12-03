// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZEROGDELIVERY_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "PauseMenu")
	void OnResumePressed();

	UFUNCTION(BlueprintCallable, Category = "PauseMenu")
	void OnExitPressed();
};
