// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "MyTankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKWARS_API ATank : public APawn
{
	GENERATED_BODY()
		
public:
	// Sets default values for this pawn's properties
	ATank();


	void AimAt(FVector OutHitLocation) const;
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrel(UTankBarrel* Barrel);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurret(UTankTurret* Turret);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	// Called when the game starts or when spawned
	
	UMyTankAimingComponent * TankAimingComponent = nullptr;

private:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.f; // TODO find reasonable default speed for projectile
};
