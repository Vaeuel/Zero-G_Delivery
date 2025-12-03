// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "Blueprint/UserWidget.h"
#include "GM_ZeroGDeliveryBase.generated.h" //This must run last, so any libraries that get added must go before this

/**
 * 
 */
UCLASS() //Engine specific definition. would need to dig deep to understand it. 'U' may represent unreal?
class ZEROGDELIVERY_API AGM_ZeroGDeliveryBase : public AGameModeBase //What does the 'A' stand for? Stands for Actor. there are a few prefixs used in defining what this script represents "A,U,P, Etc."
{

	GENERATED_BODY() //Unreal functionality

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Score")
    int32 CurrentScore = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Score")
    int32 DeliveriesMade = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Score")
    int32 DeliveryGoal = 0;

public:
	virtual void StartPlay() override; //Find over rides in documentation

	void TogglePauseMenu();

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Amount);

    UFUNCTION(BlueprintCallable, Category = "Score")
    void SetScore(int32 NewScore);

    UFUNCTION(BlueprintCallable, Category = "Score")
    int32 GetScore() const;

    UFUNCTION(BlueprintCallable, Category = "Score")
    void CheckForEndGame();

	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<class UUserWidget> PauseMenuClass; //Must be assigned in editor

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> EndGameMenuClass;

private:
	UPROPERTY()
	class UUserWidget* PauseMenuInstance = nullptr;

    UPROPERTY()
    UUserWidget* EndGameMenuInstance = nullptr;
};
