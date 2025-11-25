// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "GM_ZeroGDeliveryBase.generated.h" //This must run last, so any libraries that get added must go before this

/**
 * 
 */
UCLASS() //Engine specific definition. would need to dig deep to understand it. 'U' may represent unreal?
class ZEROGDELIVERY_API AGM_ZeroGDeliveryBase : public AGameModeBase //What does the 'A' stand for? Stands for Actor. there are a few prefixs used in defining what this script represents "A,U,P, Etc."
{
	GENERATED_BODY() //Unreal functionality

	virtual void StartPlay() override; //Find over rides in documentation

};
