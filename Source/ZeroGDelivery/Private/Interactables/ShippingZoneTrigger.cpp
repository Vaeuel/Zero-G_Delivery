// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/ShippingZoneTrigger.h"
#include "Interactables/ShippingContainer.h"
#include "GM_ZeroGDeliveryBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Player/DroneCharacter.h"

// Sets default values
AShippingZoneTrigger::AShippingZoneTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(Root);
	
	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	VisualMesh->SetGenerateOverlapEvents(false);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube"));
	if (MeshAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(MeshAsset.Object);
	}

	VisualMesh->SetRelativeScale3D(FVector(20.f, 10.f, 20.f)); 
	VisualMesh->SetRelativeLocation(FVector::ZeroVector);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(Root);
	TriggerBox->SetRelativeLocation(FVector::ZeroVector);
	TriggerBox->InitBoxExtent(VisualMesh->Bounds.BoxExtent);
	TriggerBox->SetRelativeScale3D(FVector(20.f, 10.f, 20.f));
	TriggerBox->SetCollisionProfileName("Trigger");
	TriggerBox->SetGenerateOverlapEvents(true);

	DeliveryBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DeliveryBox"));
	DeliveryBox->SetupAttachment(Root);
	DeliveryBox->InitBoxExtent(VisualMesh->Bounds.BoxExtent);
	DeliveryBox->SetRelativeScale3D(FVector(20.f, 10.f, 1.f));
	DeliveryBox->SetRelativeLocation(FVector::ZeroVector);
	DeliveryBox->SetCollisionProfileName("Trigger");
	DeliveryBox->SetHiddenInGame(!IsDeliveryPoint);
	DeliveryBox->SetGenerateOverlapEvents(IsDeliveryPoint);
}

void AShippingZoneTrigger::BeginPlay()
{
	Super::BeginPlay();
	GM = Cast<AGM_ZeroGDeliveryBase>(GetWorld()->GetAuthGameMode());

	InitBindings();

	if (IsDeliveryPoint && VisualMesh)
	{
		UMaterial* Mat = LoadObject<UMaterial>(nullptr, TEXT("/Game/Materials/M_Trigger_DP.M_Trigger_DP"));
		if (Mat) VisualMesh->SetMaterial(0, Mat);
		DeliveryBox->SetHiddenInGame(!IsDeliveryPoint);
		DeliveryBox->SetGenerateOverlapEvents(IsDeliveryPoint);
	}

	if (!IsDeliveryPoint && VisualMesh)
	{
		UMaterial* Mat = LoadObject<UMaterial>(nullptr, TEXT("/Game/Materials/M_Trigger.M_Trigger"));
		if (Mat) VisualMesh->SetMaterial(0, Mat);
		DeliveryBox->SetHiddenInGame(!IsDeliveryPoint);
		DeliveryBox->SetGenerateOverlapEvents(IsDeliveryPoint);
	}
}

void AShippingZoneTrigger::InitBindings()
{
	if(TriggerBox)
	{
		TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AShippingZoneTrigger::OnOverlapBegin);
		TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AShippingZoneTrigger::OnOverlapEnd);
	}

	if (DeliveryBox) DeliveryBox->OnComponentBeginOverlap.AddDynamic(this, &AShippingZoneTrigger::OnDeliveryBoxOverlap);
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
	if (!Drone->HeldContainer) GM->ShowHUD(false);
}
void AShippingZoneTrigger::OnDeliveryBoxOverlap(
	UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 BodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	AShippingContainer* Container = Cast<AShippingContainer>(OtherActor);
	if (!Container) return;

	if (Container->IsDelivered) return;

	if (GM)
	{
		GM->ReportDelivery(Container->GetHealthPercent());
		GM->CheckForEndGame();
	}

	Container->IsDelivered = true; //Functionality completed? Set nullptr here?
	
}