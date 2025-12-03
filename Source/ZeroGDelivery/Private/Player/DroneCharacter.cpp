// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/DroneCharacter.h"
#include "Interactables/ShippingContainer.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GM_ZeroGDeliveryBase.h"

//Constructor that sets default values
ADroneCharacter::ADroneCharacter() //Constructor - Happens when the editor executes and/ or when the code executes during run time. Null* here will generate an infinite loop and crash.
{
	bUseControllerRotationYaw = false;
	PrimaryActorTick.bCanEverTick = true; //Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	DroneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DroneMesh"));
	SetRootComponent(DroneMesh);
	DroneMesh->SetSimulatePhysics(true);
	DroneMesh->SetLinearDamping(0.2f);
	DroneMesh->SetAngularDamping(0.6f);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(DroneMesh);
	SpringArm->TargetArmLength = 1800.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 2.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ADroneCharacter::BeginPlay()
{
	Super::BeginPlay();
	CalculateCenterOfMass();
}

// Called every frame
void ADroneCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ApplyHoverForce(); //Neutralize gravity and maintain vertical lock
	StabilizeUpright(); //Keep drone Upright (No pitch/roll drift)

	CurrentYawInput = FMath::Lerp(CurrentYawInput, TargetYawInput, 0.002f);
	//CurrentYawInput = FMath::FInterpTo(CurrentYawInput, TargetYawInput, DeltaTime, YawResponseSpeed);

	RotateYaw(CurrentYawInput);
	DebugDrawPhysics();
}

// Called to bind functionality to input
void ADroneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Movement
	PlayerInputComponent->BindAxis("MoveForwardReverse", this, &ADroneCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveStrafe", this, &ADroneCharacter::MoveStrafe);
	PlayerInputComponent->BindAxis("Turn", this, &ADroneCharacter::OnYawInput); //Bind raw axis to set target

	PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &ADroneCharacter::TryGrab);
	PlayerInputComponent->BindAction("PickUp", IE_Released, this, &ADroneCharacter::ReleaseGrab);

	PlayerInputComponent->BindAction("PutDown", IE_Pressed, this, &ADroneCharacter::TryDrop);
	PlayerInputComponent->BindAction("PutDown", IE_Released, this, &ADroneCharacter::ReleaseDrop);

	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &ADroneCharacter::PauseMenu);
}

void ADroneCharacter::MoveForward(float Value)
{
	if (FMath::IsNearlyZero(Value)) return;

	FVector Dir = GetActorForwardVector();
	Dir.Z = 0.f;
	Dir.Normalize();

	//FVector Offset = GetActorForwardVector() * 100.f; //Don't think I need this. Must test.
	//DroneMesh->AddForceAtLocation(Force, DroneMesh->GetComponentLocation() + Offset); //Can use this and the above for turning.
	FVector Force = Dir * (ThrustStrength * Value);
	DroneMesh->AddForce(Force);
}

void ADroneCharacter::MoveStrafe(float Value)
{
	if (FMath::IsNearlyZero(Value)) return;

	FVector Dir = GetActorRightVector();
	Dir.Z = 0.f;
	Dir.Normalize();

	FVector Force = Dir * (ThrustStrength * Value);
	DroneMesh->AddForce(Force);
}

void ADroneCharacter::CalculateCenterOfMass()
{
	if (!DroneMesh) return;

	FVector Origin, BoxExtent;
	DroneMesh->GetLocalBounds(Origin, BoxExtent); //Gets half-size of mesh in each axis

	const float OffsetDist = BoxExtent.X * 1.2f; //About 120% of half-width, tweak as needed
	CenterOfMassOffset = FVector (-OffsetDist, 0.f, 0.f);

	DroneMesh->SetCenterOfMass(CenterOfMassOffset); //Needs to be here for logic
}

void ADroneCharacter::RotateYaw(float Value)
{
	if (FMath::IsNearlyZero(Value)) return;

	FVector Force = GetActorRightVector() * (YawThrustStrength * Value);
	YawForceLoc = DroneMesh->GetComponentLocation() + DroneMesh->GetComponentTransform().TransformVector(CenterOfMassOffset * -1.5f);
	DroneMesh->AddForceAtLocation(Force, YawForceLoc);

	FVector AngVel = DroneMesh->GetPhysicsAngularVelocityInRadians();
	AngVel.Z = FMath::Clamp(AngVel.Z, -2.f, 2.f); //rad/s limit
	DroneMesh->SetPhysicsAngularVelocityInRadians(AngVel, false);
}

void ADroneCharacter::OnYawInput(float Value)
{
	TargetYawInput = (FMath::Abs(Value) < .1f) ? 0.f : Value; //Adds small deadzone... Adjust based on feel
}

void ADroneCharacter::ApplyHoverForce() //Apply equal upward force to cancel gravity
{
	if (!DroneMesh) return;

	const float Gravity = GetWorld()->GetGravityZ();
	const float Mass = DroneMesh->GetMass();
	FVector AntiGravity = FVector(0.f, 0.f, -Gravity * Mass);
	DroneMesh->AddForce(AntiGravity);
}

void ADroneCharacter::StabilizeUpright() //Apply corrective torque to remove roll/pitch
{
	if (!DroneMesh) return;

	FRotator Current = DroneMesh->GetComponentRotation();
	FRotator Delta = FRotator(-Current.Pitch, 0.f, -Current.Roll);

	FVector Correction = FVector(Delta.Pitch, Delta.Roll, 0.f) * LevelingTorque;
	DroneMesh->AddTorqueInRadians(Correction);
}

void ADroneCharacter::DebugDrawPhysics()
{
	if (!DroneMesh) return;

	// World-space CoM
	FVector WorldCoM = DroneMesh->GetComponentLocation() +
		DroneMesh->GetComponentTransform().TransformVector(CenterOfMassOffset);

	// Last applied force point (front offset)
	FVector ForcePoint = YawForceLoc;

	DrawDebugSphere(GetWorld(), WorldCoM, 15.f, 8, FColor::Yellow, false, -1.f, 0, 2.f);
	DrawDebugSphere(GetWorld(), ForcePoint, 15.f, 8, FColor::Blue, false, -1.f, 0, 2.f);
	DrawDebugLine(GetWorld(), WorldCoM, ForcePoint, FColor::Cyan, false, -1.f, 0, 1.f);
}

AShippingContainer* ADroneCharacter::FindContainer()
{
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + (Camera->GetForwardVector() * GrabRange);

	FHitResult Hit;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);

	bool bHit = GetWorld()->SweepSingleByChannel(
		Hit,
		Start,
		End,
		FQuat::Identity,
		ECC_PhysicsBody,
		Sphere
	);

	if (bHit)
		return Cast<AShippingContainer>(Hit.GetActor());

	return nullptr;
}

void ADroneCharacter::TryGrab()
{
	if (!bCanGrabInThisZone) return;

	if (HeldContainer) return;

	AShippingContainer* Container = FindContainer();
	if (!Container) return;

	Container->StartGrab(this);
	HeldContainer = Container;
}

void ADroneCharacter::ReleaseGrab()
{
	if (!HeldContainer) return;

	HeldContainer->StopGrab();
	HeldContainer = nullptr;
}

void ADroneCharacter::TryDrop()
{
}

void ADroneCharacter::ReleaseDrop()
{
}

void ADroneCharacter::PauseMenu()
{
	if (auto GameModeRef = Cast<AGM_ZeroGDeliveryBase>(GetWorld()->GetAuthGameMode()))
	{
		GameModeRef->TogglePauseMenu();
	}
}

void ADroneCharacter::OnEnterCargoZone()
{
	UE_LOG(LogTemp, Warning, TEXT("Entered Cargo Zone!"));
}

void ADroneCharacter::OnExitCargoZone()
{
	UE_LOG(LogTemp, Warning, TEXT("Left Cargo Zone!"));
}