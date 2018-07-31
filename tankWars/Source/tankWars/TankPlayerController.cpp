// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"

void ATankPlayerController::BeginPlay() {
	
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();

	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller in BeginPlay attached to player %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Player Controller not Found"));
	}
	

}


void ATankPlayerController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);
	AimCrosshairs();
	
}

ATank* ATankPlayerController::GetControlledTank() const {
	
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimCrosshairs() {
	
	// if there's no tank - return
	if (!GetControlledTank()) { return; }
	FVector OutHitLocation;

	if (GetAimLocation(OutHitLocation)) {
		//Rotate tank's turret to AimLocation
	}
}


bool ATankPlayerController::GetAimLocation(FVector& OutHitLocation) const {
	
	// Get 2D pixel coordinates for crosshairs location
	int32 ViewPort_X, ViewPort_Y ;

	GetViewportSize(ViewPort_X, ViewPort_Y);
	FVector2D CrosshairLocation = FVector2D(ViewPort_X * CrossHair_X, ViewPort_Y * CrossHair_Y);
	
	
	// "de-project" the 2D coord into 3D space and LineTrace the projection
	FVector LookDirection;
	FHitResult HitResult;

	if (GetTraceHitLocation(CrosshairLocation, LookDirection, HitResult)) {
		
		OutHitLocation = HitResult.Location;
		UE_LOG(LogTemp, Warning, TEXT("TraceEnd Coordinates %s"), *OutHitLocation.ToString())
		return true;
	}
	

	return false;
}

bool ATankPlayerController::GetTraceHitLocation(FVector2D CrosshairLocation, FVector& LookDirection, FHitResult& HitResult) const {

	FVector CameraLocation;

	// de-projecting
	DeprojectScreenPositionToWorld(
			CrosshairLocation.X,
			CrosshairLocation.Y,
			CameraLocation, // OUT parameter to get player camera location
			LookDirection // Unit vector representing direction of crosshairs

		);

	auto response = FCollisionResponseParams();
	auto params = FCollisionQueryParams();

	//Line Trace
	return GetWorld()->LineTraceSingleByChannel(
			HitResult, // Saves the result in this OUT parameter
			CameraLocation, // StartPoint
			CameraLocation + LookDirection * LineTraceRange, // EndPoint
			ECollisionChannel::ECC_Visibility,
			params,
			response

		);
}


