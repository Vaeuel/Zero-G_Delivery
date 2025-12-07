// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <PhysicsEngine/PhysicsHandleComponent.h>
#include <PhysicsEngine/PhysicsConstraintComponent.h>
#include "DroneCharacter.generated.h"

class AShippingContainer; //Forward declaration?

UCLASS()
class ZEROGDELIVERY_API ADroneCharacter : public APawn //Need to inherit from a blank controllable Entity if I'm going to build fully physics driven motion.
{
	GENERATED_BODY()

public:
	ADroneCharacter(); //Sets default values
	void ToggleContainerLock(bool bIsLocked);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	bool IsGravityGunActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	bool IsCanLower = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	AShippingContainer* HeldContainer = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	AShippingContainer* TargetContainer = nullptr;

protected:
	virtual void BeginPlay() override; //Called when the game starts or when spawned
	virtual void Tick(float DeltaTime) override; //Called every frame
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; //Called to bind functionality to input

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DroneMesh;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	UPhysicsHandleComponent* PhysicsHandle;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	FTransform CargoOffset;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ThrustStrength = 3000.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float YawThrustStrength = 1.0f;

	FVector YawForceLoc = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float YawResponseSpeed = 3.f; //Effects how abruptly the rotation stops VIA interp to

	float CurrentYawInput = 0.f;
	float TargetYawInput = 0.f;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	FVector CenterOfMassOffset = FVector::ZeroVector; //Stores Center of mass offset in local space

	UPROPERTY(EditAnywhere, Category = "Stabilization")
	float LevelingTorque = 200.f;

	UPROPERTY(EditAnywhere, Category = "GravityGun")
	float GrabRange = 3000.f;

	UPROPERTY(EditAnywhere, Category = "GravityGun")
	float GrabRadius = 400.f;

	UPROPERTY(VisibleAnywhere)
	class UDecalComponent* LandingShadowDecal;

	void MoveForward(float Value);
	void MoveStrafe(float Value);
	void RotateYaw(float Value); //Applies yaw using the Given (Smoothed) Value
	void OnYawInput(float Value); //Raw axis binding that sets TargetYawInput

	void TryGrab();
	void ReleaseGrab();
	void TryDrop();
	void ReleaseDrop();
	void PauseMenu();

private:
	void CalculateCenterOfMass();
	void ApplyHoverForce();
	void StabilizeUpright();

	void DebugDrawPhysics(); //Temp Debug Function for rotation

};
