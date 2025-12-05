// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/ShippingContainer.h"
#include "GM_ZeroGDeliveryBase.h"
#include <Player/DroneCharacter.h>

// Sets default values
AShippingContainer::AShippingContainer()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->BodyInstance.bUseCCD = true;
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetLinearDamping(0.4f);
	Mesh->SetAngularDamping(0.8f);

	// Collision callback
	Mesh->OnComponentHit.AddDynamic(this, &AShippingContainer::OnHit);

	CurrentHealth = MaxHealth;
}

void AShippingContainer::BeginPlay()
{
	Super::BeginPlay();
}

void AShippingContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsBeingPulled && HeldByDrone && !IsAttached) ApplyPickupForce(DeltaTime);

	if (CanAttach && !IsAttached && !IsLowering) ToggleAttachment(HeldByDrone);

	if (IsLowering) LowerCargo();

	if (IsDelivered) EndLife();
}

void AShippingContainer::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor && OtherActor == HeldByDrone) CanAttach = true;
}

void AShippingContainer::ToggleAttachment(AActor* Drone)
{
	if (!Drone) return;
	IsAttached = !IsAttached;
	
	Mesh->SetPhysicsLinearVelocity(FVector::ZeroVector, false);
	Mesh->SetSimulatePhysics(!IsAttached);

	if (IsAttached)
	{
		AttachToActor(Drone, FAttachmentTransformRules::KeepWorldTransform);
		if (Drone) HeldByDrone->HeldContainer = this;
		CanAttach = false;
		StartTimer();
	}

	else
	{
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		if (Drone) HeldByDrone->HeldContainer = nullptr;
	}
}

void AShippingContainer::StartGravityGun(AActor * InDrone)
{
	if (IsAttached) return;
	if (!HeldByDrone)
	{
		ADroneCharacter* DroneRef = Cast<ADroneCharacter>(InDrone);
		if (!DroneRef) return;
		HeldByDrone = DroneRef; //Must add Clear later when teh container is delivered/destroyed **HeldByDrone = nullptr;
	}
	IsBeingPulled = true;
	IsLowering = false;
}

void AShippingContainer::StartGravity() //Need to modify to ignore -Velocity
{
	if (IsAttached) return;
	if (!Mesh) return;

	IsBeingPulled = false;

	Mesh->SetSimulatePhysics(true);
	Mesh->SetPhysicsLinearVelocity(FVector::ZeroVector, false);
}

void AShippingContainer::LowerCargo()
{
	if (!Mesh) return;
	//IsLowering = true;

	if(IsAttached && HeldByDrone)
	{
		HeldByDrone->IsCanLower = true;
		ToggleAttachment(HeldByDrone);
		StartGravity();
	}
	//IsAttached = false;
	FVector LiftForce = CalculateLift(.9f);
	Mesh->AddForce(LiftForce);
}

void AShippingContainer::ApplyPickupForce(float DeltaTime)
{
	if (!HeldByDrone) return;
	if (!Mesh) return;

	FVector ToDrone = HeldByDrone->GetActorLocation() - GetActorLocation();
	FVector ForceDir = ToDrone.GetSafeNormal();
	FVector LiftForce = CalculateLift(1.3f);

	PickupForce = LiftForce.Z * .2f;
	FVector Force = ForceDir * PickupForce;

	Mesh->AddForce(LiftForce);
	Mesh->AddForce(Force);
}

FVector AShippingContainer::CalculateLift(float Multiplier)
{
	const float Gravity = GetWorld()->GetGravityZ();
	const float Mass = Mesh->GetMass();

	float LiftAmount = (-Gravity * Mass) * Multiplier;
	return FVector(0, 0, LiftAmount);
}

void AShippingContainer::StartTimer()
{
	AGM_ZeroGDeliveryBase* GM = Cast<AGM_ZeroGDeliveryBase>(GetWorld()->GetAuthGameMode());
	if (GM) GM->IsTimerRunning = true;
}

void AShippingContainer::EndLife()
{
	HeldByDrone->IsGravityGunActive = false;
	HeldByDrone->HeldContainer = nullptr;
	//Reset or destroy?
}

void AShippingContainer::OnHit(
	UPrimitiveComponent * HitComp,
	AActor * OtherActor,
	UPrimitiveComponent * OtherComp,
	FVector NormalImpulse,
	const FHitResult & Hit)
{
	if (OtherActor == HeldByDrone) return; //Ignore drone contact

	float Impact = NormalImpulse.Size();
	float Damage = Impact * DamageMultiplier;

	CurrentHealth -= Damage;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.f, MaxHealth);
}

float AShippingContainer::GetHealthPercent() const
{
	return CurrentHealth / MaxHealth;
}
