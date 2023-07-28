// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Soul.generated.h"

/**
 * 
 */
UCLASS()
class SLASHTUTORIAL_API ASoul : public AItem
{
	GENERATED_BODY()
public:
	/** <AActor> */
	virtual void Tick(float DeltaTime) override;
	/** </AActor> */

protected:
	/** <AActor> */
	virtual void BeginPlay() override;
	/** <AActor> */

	virtual void OnSphereBeginOvelrap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
private:
	float SetDesiredZ();
	void SoulDrift(float DeltaTime);

	float DesiredZ;

	UPROPERTY(EditAnywhere, Category = "Soul Properties")
	float DriftZ = -20.f;

	UPROPERTY(EditAnywhere, Category = "Soul Properties")
	float ZOffset = 50.f;

	UPROPERTY(EditAnywhere, Category = "Soul Properties")
	float ZEndTrace = 2000.f;

	UPROPERTY(EditAnywhere, Category = "Soul Properties")
	int32 Souls;

public:
	FORCEINLINE int32 GetSouls() const { return Souls; }
	FORCEINLINE void SetSouls(int32 Amount) { Souls = Amount; }
};
