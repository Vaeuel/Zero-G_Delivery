// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DroneCharacter.generated.h"

UCLASS()
class ZEROGDELIVERY_API ADroneCharacter : public APawn //Need to inherit from a blank controllable Entity if I'm going to build fully physics driven motion.
{
	GENERATED_BODY()

public:
	ADroneCharacter(); //Sets default values

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

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ThrustStrength = 400.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float YawThrustStrength = .02f;

	FVector YawForceLoc = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float YawResponseSpeed = 4.f;

	float CurrentYawInput = 0.f;
	float TargetYawInput = 0.f;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	FVector CenterOfMassOffset = FVector::ZeroVector; //Stores Center of mass offset in local space

	UPROPERTY(EditAnywhere, Category = "Stabilization")
	float LevelingTorque = 200.f;


	void MoveForward(float Value);
	void MoveStrafe(float Value);
	void RotateYaw(float Value); //Applies yaw using the Given (Smoothed) Value
	void OnYawInput(float Value); //Raw axis binding that sets TargetYawInput

private:
	void CalculateCenterOfMass();
	void ApplyHoverForce();
	void StabilizeUpright();

	void DebugDrawPhysics(); //Temp Debug Function for rotation

};
