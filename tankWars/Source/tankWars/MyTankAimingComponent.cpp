// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankAimingComponent.h"
#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"


// Sets default values for this component's properties
UMyTankAimingComponent::UMyTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

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


bool UMyTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed) const {

	if (!Barrel) { return false; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("LaunchPoint"));
	TArray<AActor*> ActorsToIgnore;
	if (UGameplayStatics::SuggestProjectileVelocity(GetWorld(), OutLaunchVelocity, StartLocation, OutHitLocation, LaunchSpeed, false,
													50.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace
	)) {

		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s is Firing at speed: %s"), *GetOwner()->GetName(), *AimDirection.ToString())
		FRotator CurrentBarrelRotation = Barrel->GetForwardVector().Rotation();
		FRotator NewBarrelRotation = AimDirection.Rotation();
		FRotator DeltaRotation = NewBarrelRotation - CurrentBarrelRotation;
		Barrel->Elevate(DeltaRotation.Pitch);
		
		if (!Turret) { UE_LOG(LogTemp, Error, TEXT("No Turret Found"));  return false; }
		else {
			if (Turret->Rotate(DeltaRotation.Yaw) == NewBarrelRotation.Yaw) return true;
			
		}
	}

	return false;

}

void UMyTankAimingComponent::SetBarrel(UTankBarrel * Barrel) {

	this->Barrel = Barrel;
}

void UMyTankAimingComponent::SetTurret(UTankTurret * Turret)
{
	this->Turret = Turret;
}

