// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/ShippingZoneTrigger.h"
#include "Interactables/ShippingContainer.h"
#include "GM_ZeroGDeliveryBase.h"
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
	TriggerBox->SetGenerateOverlapEvents(true);

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

	DeliveryBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DeliveryBox"));
	DeliveryBox->InitBoxExtent(FVector(1000.f, 500.f, 50.f));

	DeliveryBox->SetupAttachment(TriggerBox);

	DeliveryBox->SetCollisionProfileName("Trigger");
	DeliveryBox->SetGenerateOverlapEvents(true);
}

void AShippingZoneTrigger::BeginPlay()
{
	Super::BeginPlay();
	GM = Cast<AGM_ZeroGDeliveryBase>(GetWorld()->GetAuthGameMode());

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AShippingZoneTrigger::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AShippingZoneTrigger::OnOverlapEnd);

	DeliveryBox->OnComponentBeginOverlap.AddDynamic(this, &AShippingZoneTrigger::OnDeliveryBoxOverlap);
}

void AShippingZoneTrigger::OnOverlapBegin(
	UPrimitiveComponent * OverlappedComp, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 BodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ADroneCharacter* Drone = Cast<ADroneCharacter>(OtherActor);
	if (!Drone) return;

	Drone->IsGravityGunActive = true; //For camera angle change, HUD etc.
	GM->ShowHUD(true);
}

void AShippingZoneTrigger::OnOverlapEnd(
	UPrimitiveComponent * OverlappedComp, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 BodyIndex)
{
	ADroneCharacter* Drone = Cast<ADroneCharacter>(OtherActor);
	if (!Drone) return;

	Drone->IsGravityGunActive = false; //Camera resets, HUD hides, etc.
	if (Drone->HeldContainer == nullptr) GM->ShowHUD(false);
}
void AShippingZoneTrigger::OnDeliveryBoxOverlap(
	UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 BodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	AShippingContainer* Container = Cast<AShippingContainer>(OtherActor);
	if (!Container) return;

	if (Container->IsDelivered) return;

	//AGM_ZeroGDeliveryBase* GM = Cast<AGM_ZeroGDeliveryBase>(GetWorld()->GetAuthGameMode());
	if (GM)
	{
		GM->ReportDelivery(Container->GetHealthPercent());
		GM->CheckForEndGame();
	}

	Container->IsDelivered = true; //Functionality completed? Set nullptr here?
	
}