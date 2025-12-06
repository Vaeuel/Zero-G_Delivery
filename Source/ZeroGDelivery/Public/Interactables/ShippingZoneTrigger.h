// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShippingZoneTrigger.generated.h"

UCLASS()
class ZEROGDELIVERY_API AShippingZoneTrigger : public AActor
{
	GENERATED_BODY()

public:
	AShippingZoneTrigger();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	class AGM_ZeroGDeliveryBase* GM = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Delivery")
	class UBoxComponent* DeliveryBox;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delivery")
	bool IsDeliveryPoint = false;

	// Events
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 BodyIndex);

	UFUNCTION()
	void OnDeliveryBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void InitBindings();
};
