// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankAIController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

void  AMyTankAIController::BeginPlay() {
	
	Super::BeginPlay();
	
	ATank* ControlledTank = GetControlledTank();

	// Check for AIcontrolled tank
	if (ControlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing Tank : %s"), *ControlledTank->GetName())
	}
	else {

		UE_LOG(LogTemp, Error, TEXT("Controlled tank not found"))
	}


	// Check for PlayerControlled tank
	if (GetPlayerTank()) {

		UE_LOG(LogTemp, Warning, TEXT("AI controller found player tank : %s"), *GetPlayerTank()->GetName())
	}
	else {

		
	}
}
	
void AMyTankAIController::Tick(float deltaTime) {

	Super::Tick(deltaTime);

	if (GetPlayerTank()) {

		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		GetControlledTank()->Fire();
	}
	
}

ATank* AMyTankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}


ATank* AMyTankAIController::GetPlayerTank() const {

	AActor* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (PlayerTank) {

		return Cast<ATank>(PlayerTank);
	}
	else {

		return nullptr;
	}
	
}