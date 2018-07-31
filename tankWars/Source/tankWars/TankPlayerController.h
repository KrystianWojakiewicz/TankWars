// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKWARS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

private:
	
	ATank * GetControlledTank() const;
	// Moves tank's turret to crosshairs location
	void AimCrosshairs();

	// Gets the coordinates of Object hit by Line Trace. Returns 1 if hit terrain or enemy tank, 0 otherwise
	bool GetAimLocation(FVector& OutHitLocation) const;



	// de-projects 2D vector of crosshair to 3D world vector and Line Traces
	bool GetTraceHitLocation(FVector2D CrosshairLocation, FVector & LookDirection, FHitResult& HitResult) const;
	


	UPROPERTY(EditAnywhere)
	float CrossHair_X = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrossHair_Y = 0.333333;
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 10000000.f;
};
