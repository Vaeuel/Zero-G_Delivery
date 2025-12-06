// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShippingContainer.generated.h"

class ADroneCharacter;

UCLASS()
class ZEROGDELIVERY_API AShippingContainer : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AShippingContainer();

	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	void StartGravityGun(AActor* InDrone); //Called by Drone to start lifting
	void LowerCargo(); //Called by drone to start lowering
	void StartGravity(); //Called when drone releases

	float GetHealthPercent() const; //Returns Current health

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	bool IsBeingPulled = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	bool IsLowering = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	bool IsAttached = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	bool IsDelivered = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	bool CanAttach = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY()
	ADroneCharacter* HeldByDrone = nullptr;

	UPROPERTY()
	FTimerHandle DestroyTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Container")
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Container")
	float PickupForce = 0.f;   //upward physics force toward drone

	UPROPERTY(EditAnywhere, Category = "Container")
	float DamageMultiplier = 0.02f;

private:
	float CurrentHealth;

	//AActor* PullingDrones = nullptr; //Switching to class specific variable. Must convert all.

	void ApplyPickupForce(float DeltaTime);
	FVector CalculateLift(float Multiplier);

	void ToggleAttachment(AActor* Drone);
	void StartTimer();
	void EndLife();
	void DestroySelf();

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
