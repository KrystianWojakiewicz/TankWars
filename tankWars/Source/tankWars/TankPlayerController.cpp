// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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

ATank* ATankPlayerController::GetControlledTank() const {
	
	return Cast<ATank>(GetPawn());
}

