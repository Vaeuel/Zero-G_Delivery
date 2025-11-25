// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
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

	UFUNCTION()
	void UpdateCargoIntegrity(float IntegrityPercent);
};
