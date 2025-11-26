// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/ButtonWidget.h"

void UButtonWidget::SetText(int Value)
{
	if (!Button || !Text) return;

	Num = Value;
	Text->SetText(FText::FromString(FString::Printf(TEXT("%d"), Num)));
	Button->OnClicked.AddDynamic(this, &UButtonWidget::OnButtonClick);
}

void UButtonWidget::OnButtonClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Button %d Clicked"), Num);
}