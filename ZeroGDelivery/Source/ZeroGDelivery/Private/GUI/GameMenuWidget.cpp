// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameMenuWidget.h"

void UGameMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateCargoIntegrity(1.0f);
}

void UGameMenuWidget::UpdateCargoIntegrity(float IntegrityPercent)
{
	if (!CargoIntegrity) return;

	CargoIntegrity->SetPercent(IntegrityPercent);
}
