// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ScoreGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ZEROGDELIVERY_API UScoreGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

    UPROPERTY(BlueprintReadWrite)
    int32 PreviousScore = 0;

    UPROPERTY(BlueprintReadWrite)
    int32 BestScore = 0;
};
