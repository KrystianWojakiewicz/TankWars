// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h "


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UMyTankAimingComponent>(FName("TankAimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector OutHitLocation) const {

	TankAimingComponent->AimAt(OutHitLocation, LaunchSpeed);
	
}

void ATank::SetBarrel(UTankBarrel * Barrel) {

	TankAimingComponent->SetBarrel(Barrel);
	this->Barrel = Barrel;
}

void ATank::SetTurret(UTankTurret * Turret)
{
	TankAimingComponent->SetTurret(Turret);
}

void ATank::Fire()
{
	if (!Barrel) { UE_LOG(LogTemp, Error, TEXT("No Barrel Attatched")) return; }

	FVector SpawnLocation = Barrel->GetSocketLocation(FName("LaunchPoint"));
	FRotator SpawnRotation = Barrel->GetSocketRotation(FName("LaunchPoint"));
	UE_LOG(LogTemp, Warning, TEXT("Tank is firing"))
	GetWorld()->SpawnActor<AProjectile>(Projectile, SpawnLocation, SpawnRotation);

}