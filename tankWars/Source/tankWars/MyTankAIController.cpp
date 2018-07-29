// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankAIController.h"

void  AMyTankAIController::BeginPlay() {
	ATank* ControlledTank = GetControlledTank();

	if (ControlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing Tank : %s"), *ControlledTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing Tank : %s"), *ControlledTank->GetName())
	}
}
	

ATank* AMyTankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

