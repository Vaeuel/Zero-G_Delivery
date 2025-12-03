// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/ShippingContainer.h"

// Sets default values
AShippingContainer::AShippingContainer()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

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

	if (bBeingPulled && PullingDrone && !bAttached)
	{
		ApplyPickupForce(DeltaTime);

		// Check if close enough to attach
		float Dist = FVector::Dist(GetActorLocation(), PullingDrone->GetActorLocation());
		if (Dist < 150.f)
		{
			bAttached = true;
			bBeingPulled = false;

			Mesh->SetSimulatePhysics(false);
			AttachToActor(PullingDrone, FAttachmentTransformRules::KeepWorldTransform);
		}
	}
}

void AShippingContainer::StartGrab(AActor * InDrone)
{
	if (bAttached) return;

	PullingDrone = InDrone;
	bBeingPulled = true;
}

void AShippingContainer::StopGrab()
{
	if (!bAttached) return;

	bAttached = false;
	PullingDrone = nullptr;

	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	Mesh->SetSimulatePhysics(true);
}

void AShippingContainer::ApplyPickupForce(float DeltaTime)
{
	FVector ToDrone = PullingDrone->GetActorLocation() - GetActorLocation();

	// Always pull upward
	if (ToDrone.Z < 50.f)
		ToDrone.Z = 50.f;

	FVector ForceDir = ToDrone.GetSafeNormal();
	FVector Force = ForceDir * PickupForce;

	Mesh->AddForce(Force);
}

void AShippingContainer::OnHit(
	UPrimitiveComponent * HitComp,
	AActor * OtherActor,
	UPrimitiveComponent * OtherComp,
	FVector NormalImpulse,
	const FHitResult & Hit)
{
	if (OtherActor == PullingDrone) return; //Ignore drone contact

	float Impact = NormalImpulse.Size();
	float Damage = Impact * DamageMultiplier;

	CurrentHealth -= Damage;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.f, MaxHealth);
}

float AShippingContainer::GetHealthPercent() const
{
	return CurrentHealth / MaxHealth;
}
