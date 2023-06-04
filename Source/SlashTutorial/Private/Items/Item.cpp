// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "SlashTutorial/DebugMacros.h"


// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	
	DRAW_SPHERE(Location);
	//DRAW_SPHERE_COLOR(Location, FColor::Cyan);
	DRAW_BOX(Location, Location + 10.f);
	//DRAW_LINE(Location, Location + Forward * 100);
	//DRAW_POINT(Location + Forward * 100.f);
	DRAW_VECTOR(Location, Location + Forward * 100.f)
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
