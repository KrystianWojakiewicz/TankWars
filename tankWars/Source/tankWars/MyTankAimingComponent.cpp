// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "MyTankAimingComponent.h"


// Sets default values for this component's properties
UMyTankAimingComponent::UMyTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UMyTankAimingComponent::AimAt(FVector OutHitLocation) const {

	
	UE_LOG(LogTemp, Warning, TEXT("%s is aiming at : %s from location: %s"), *GetOwner()->GetName(), *OutHitLocation.ToString(), *Barrel->GetComponentLocation().ToString())
}

void UMyTankAimingComponent::SetBarrel(UStaticMeshComponent * Barrel) {

	this->Barrel = Barrel;
}

