// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/DroneCharacter.h"
#include "Interactables/ShippingContainer.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/DecalComponent.h"
#include "Components/BoxComponent.h"
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

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));

	LandingShadowDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("LandingShadow"));
	LandingShadowDecal->SetupAttachment(DroneMesh);

	LandingShadowDecal->DecalSize = FVector(400.f, 300.f, 200.f);
	LandingShadowDecal->SetVisibility(false); //hidden until needed
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

	const FRotator DefaultArmRot = FRotator(-15.f, 0.f, 0.f);
	const FRotator DefaultCamRot = FRotator(5.f, 0.f, 0.f);

	const FRotator CargoArmRot = FRotator(-50.f, 0.f, 0.f);
	const FRotator CargoCamRot = FRotator(-30.f, 0.f, 0.f);

	const FRotator TargetArmRot = IsGravityGunActive ? CargoArmRot : DefaultArmRot;
	const FRotator TargetCamRot = IsGravityGunActive ? CargoCamRot : DefaultCamRot;
	
	LandingShadowDecal->SetVisibility(IsGravityGunActive);

	if (LandingShadowDecal->IsVisible())
	{
		FVector Start = DroneMesh->GetComponentLocation();
		FVector End = Start + FVector(0, 0, -5000.f);

		FHitResult Hit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
		{
			LandingShadowDecal->SetWorldLocation(Hit.Location + Hit.Normal * 2.f);

			FRotator DecalRot = Hit.Normal.Rotation();
			DecalRot.Roll += 180.f; //decals face backwards
			LandingShadowDecal->SetWorldRotation(DecalRot);

			AShippingContainer* ContainerUnderDrone = Cast<AShippingContainer>(Hit.GetActor());

			if (ContainerUnderDrone) TargetContainer = ContainerUnderDrone;

			else TargetContainer = nullptr;
		}
	}

	if (PhysicsHandle->GetGrabbedComponent())
	{
		FTransform TargetWorld = CargoOffset * GetActorTransform(); //World transform relative to the drone

		FTransform InverseOffset = CargoOffset.Inverse();
		FTransform AnchorWorld = InverseOffset * HeldContainer->Mesh->GetComponentTransform();
		FVector AnchorLoc = AnchorWorld.GetLocation();

		FVector Delta = GetActorLocation() - AnchorLoc;
		Delta.Z = 0.f;

		const float MaxDistance = 50.f;
		if (Delta.Size2D() > MaxDistance)
		{
			FVector CorrectedLoc = AnchorLoc + Delta.GetClampedToMaxSize2D(MaxDistance);
			SetActorLocation(FVector(CorrectedLoc.X, CorrectedLoc.Y, GetActorLocation().Z));
		}
		PhysicsHandle->SetTargetLocationAndRotation(TargetWorld.GetLocation(), TargetWorld.GetRotation().Rotator()); //Effects Child (Cargo) location
	}

	const float InterpSpeed = 1.5f;

	SpringArm->SetRelativeRotation(
		FMath::RInterpTo(SpringArm->GetRelativeRotation(), TargetArmRot, DeltaTime, InterpSpeed)
	);

	Camera->SetRelativeRotation(
		FMath::RInterpTo(Camera->GetRelativeRotation(), TargetCamRot, DeltaTime, InterpSpeed)
	);

	//CurrentYawInput = FMath::Lerp(CurrentYawInput, TargetYawInput, 0.002f);
	CurrentYawInput = FMath::FInterpTo(CurrentYawInput, TargetYawInput, DeltaTime, YawResponseSpeed);

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
	if (FMath::IsNearlyZero(Value))
	{
		FVector AngVel = DroneMesh->GetPhysicsAngularVelocityInRadians();
		AngVel.Z *= 0.97f; //Damping factor ** Lower Values take off more speed/ tick? Higher values make for floaty rotation
		DroneMesh->SetPhysicsAngularVelocityInRadians(AngVel);
		return;
	}

	const float TorqueAmount = YawThrustStrength * Value;

	FVector Torque(0.f, 0.f, TorqueAmount);
	DroneMesh->AddTorqueInRadians(Torque);

	FVector AngVel = DroneMesh->GetPhysicsAngularVelocityInRadians();
	AngVel.Z = FMath::Clamp(AngVel.Z, -20.f, 20.f);

	DroneMesh->SetPhysicsAngularVelocityInRadians(AngVel);
}

void ADroneCharacter::OnYawInput(float Value)
{
	TargetYawInput = (FMath::Abs(Value) < .05f) ? 0.f : Value; //Adds small deadzone... Adjust based on feel
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

void ADroneCharacter::TryGrab()
{
	if (!IsGravityGunActive) return; //Not in cargo zone
	if (HeldContainer) return; //Already holding cargo
	if (!TargetContainer) return; //Nothing detected below the drone

	TargetContainer->StartGravityGun(this);
}

void ADroneCharacter::ReleaseGrab()
{
	if (HeldContainer || !TargetContainer) return; //Container is already attached

	TargetContainer->StartGravity();
}

void ADroneCharacter::TryDrop()
{
	if (!HeldContainer && !IsCanLower) return; //No container to drop

	TargetContainer->IsLowering = true;
}

void ADroneCharacter::ReleaseDrop()
{
	if (!IsCanLower) return; //I can lower so I can drop

	TargetContainer->IsLowering = false;
}

void ADroneCharacter::PauseMenu()
{
	if (auto GameModeRef = Cast<AGM_ZeroGDeliveryBase>(GetWorld()->GetAuthGameMode()))
	{
		GameModeRef->TogglePauseMenu();
	}
}

void ADroneCharacter::ToggleContainerLock(bool IsLocked)
{
	if (!HeldContainer || !HeldContainer->Mesh) return;

	if (IsLocked)
	{
		if (PhysicsHandle->GetGrabbedComponent()) return; //Already Holding something?

		CargoOffset = HeldContainer->Mesh->GetComponentTransform().GetRelativeTransform(GetActorTransform());

		HeldContainer->Mesh->SetSimulatePhysics(true);
		HeldContainer->Mesh->IgnoreActorWhenMoving(this, IsLocked); //Prevent Jitter from drone collision

		PhysicsHandle->GrabComponentAtLocationWithRotation(HeldContainer->Mesh, NAME_None, HeldContainer->Mesh->GetComponentLocation(), HeldContainer->Mesh->GetComponentRotation());
		return;
	}

	if (!IsLocked)
	{
		if (PhysicsHandle->GetGrabbedComponent()) //Checks to see if holding something
		{
			HeldContainer->Mesh->IgnoreActorWhenMoving(this, IsLocked); //Reenables Drone collision
			PhysicsHandle->ReleaseComponent();
		}
	}
}
