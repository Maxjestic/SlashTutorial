// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttributeComponent.h"

UAttributeComponent::UAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAttributeComponent::ReceiveDamage(float Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
}

float UAttributeComponent::GetHealthPercent() const
{
	return CurrentHealth/MaxHealth;
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

