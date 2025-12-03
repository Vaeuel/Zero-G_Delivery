// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/ShippingZoneTrigger.h"
#include "Components/BoxComponent.h"
#include "Player/DroneCharacter.h"

// Sets default values
AShippingZoneTrigger::AShippingZoneTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	SetRootComponent(TriggerBox);

	TriggerBox->InitBoxExtent(FVector(1000.f, 1000.f, 500.f));
	TriggerBox->SetCollisionProfileName("Trigger");

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(TriggerBox);

	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	VisualMesh->SetGenerateOverlapEvents(false);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube"));
	if (MeshAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(MeshAsset.Object);
	}

	VisualMesh->SetRelativeScale3D(FVector(20.f, 10.f, 20.f)); 
	VisualMesh->SetRelativeLocation(FVector::ZeroVector);
}

void AShippingZoneTrigger::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AShippingZoneTrigger::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AShippingZoneTrigger::OnOverlapEnd);
}

void AShippingZoneTrigger::OnOverlapBegin(
	UPrimitiveComponent * OverlappedComp, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 BodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ADroneCharacter* Drone = Cast<ADroneCharacter>(OtherActor);
	if (!Drone)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("SHippingZoneTrigger: .cpp: OnOverLapBegin has detected something but not a drone"));
		return;
	}

	// Tell the drone it's in range
	Drone->bCanGrabInThisZone = true;
	Drone->OnEnterCargoZone(); //For camera angle change, HUD etc.
}

void AShippingZoneTrigger::OnOverlapEnd(
	UPrimitiveComponent * OverlappedComp, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 BodyIndex)
{
	ADroneCharacter* Drone = Cast<ADroneCharacter>(OtherActor);
	if (!Drone) return;

	Drone->bCanGrabInThisZone = false;
	Drone->OnExitCargoZone(); //Camera resets, HUD hides, etc.
}
