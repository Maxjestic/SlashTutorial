// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASHTUTORIAL_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void RegenerateStamina(float DeltaTime);

protected:
	virtual void BeginPlay() override;	

private:	
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxHealth;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float CurrentStamina;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxStamina;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float DodgeCost = 10.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float StaminaRegenerationRate = 8.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	int32 Gold;	
	
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	int32 Souls;
public:
	//void SetCurrentHealth(float NewHealth);
	void ReceiveDamage(float Damage);
	void UseStamina(float StaminaCost);
	float GetHealthPercent() const;
	float GetStaminaPercent() const;
	bool IsAlive() const;
	void AddGold(int32 Amount);
	void AddSouls(int32 Amount);
	FORCEINLINE int32 GetGold() const { return Gold; }
	FORCEINLINE int32 GetSouls() const { return Souls; }
	FORCEINLINE float GetDodgeCost() const { return DodgeCost; }
	FORCEINLINE float GetStamina() const { return CurrentStamina; }
};
