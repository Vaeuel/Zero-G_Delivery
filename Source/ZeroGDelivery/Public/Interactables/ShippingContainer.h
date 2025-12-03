// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShippingContainer.generated.h"

UCLASS()
class ZEROGDELIVERY_API AShippingContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShippingContainer();

	virtual void Tick(float DeltaTime) override;

	void StartGrab(AActor* InDrone); //Called by Drone to start lifting

	void StopGrab(); //Called when drone releases

	float GetHealthPercent() const; //Returns Current health

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Container")
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Container")
	float PickupForce = 35000.f;   //upward physics force toward drone

	UPROPERTY(EditAnywhere, Category = "Container")
	float DamageMultiplier = 0.02f;

private:
	float CurrentHealth;
	bool bBeingPulled = false;
	bool bAttached = false;

	// The drone currently pulling/attached
	AActor* PullingDrone = nullptr;

	void ApplyPickupForce(float DeltaTime);

	// Collision handling
	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit
	);
};
