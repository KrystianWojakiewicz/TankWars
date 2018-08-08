// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKWARS_API UMyTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyTankAimingComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector OutHitLocation, float LaunchSpeed) const;

	void SetBarrel(UStaticMeshComponent* Barrel);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UStaticMeshComponent * Barrel = nullptr;
	
};