// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Soul.h"
#include "Interfaces/PickupInterface.h"
#include "Kismet/KismetSystemLibrary.h"

void ASoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SoulDrift(DeltaTime);
}

void ASoul::BeginPlay()
{
	Super::BeginPlay();

	DesiredZ = SetDesiredZ();
}

void ASoul::OnSphereBeginOvelrap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->AddSouls(this);
		SpawnPickupSystem();
		SpawnPickupSound();
		Destroy();
	}
}

float ASoul::SetDesiredZ()
{
	const FVector StartLocation = GetActorLocation();
	const FVector EndLocation = StartLocation - FVector(0.f, 0.f, ZEndTrace);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery1);

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());


	FHitResult HitResult;
	UKismetSystemLibrary::LineTraceSingleForObjects(
		this,
		StartLocation,
		EndLocation,
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult,
		true
	);

	return HitResult.ImpactPoint.Z + ZOffset;
}

void ASoul::SoulDrift(float DeltaTime)
{
	if (GetActorLocation().Z > DesiredZ)
	{
		const FVector DeltaLocation = FVector(0.f, 0.f, DriftZ * DeltaTime);
		AddActorWorldOffset(DeltaLocation);
	}
}