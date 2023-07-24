// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttributeComponent.h"

UAttributeComponent::UAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAttributeComponent::RegenerateStamina(float DeltaTime)
{
	CurrentStamina = FMath::Clamp(CurrentStamina + StaminaRegenerationRate * DeltaTime, 0.f, MaxStamina);
}

void UAttributeComponent::ReceiveDamage(float Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
}

void UAttributeComponent::UseStamina(float StaminaCost)
{
	CurrentStamina = FMath::Clamp(CurrentStamina - StaminaCost, 0.f, MaxStamina);
}

float UAttributeComponent::GetHealthPercent() const
{
	return CurrentHealth/MaxHealth;
}

float UAttributeComponent::GetStaminaPercent() const
{
	return CurrentStamina / MaxStamina;
}

bool UAttributeComponent::IsAlive() const
{
	return CurrentHealth > 0.f;
}

void UAttributeComponent::AddGold(int32 Amount)
{
	Gold += Amount;
}

void UAttributeComponent::AddSouls(int32 Amount)
{
	Souls += Amount;
}

