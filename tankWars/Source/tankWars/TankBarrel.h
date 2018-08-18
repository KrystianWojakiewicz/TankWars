// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKWARS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
	public:
		void Elevate(float Speed);

	private: 
		UPROPERTY(EditAnywhere, category = Setup)
		float MaxSpeedPerSecond = 10.f;
		
		UPROPERTY(EditAnywhere, category = Setup)
		float MinElevation = 0.f;

		UPROPERTY(EditAnywhere, category = Setup)
		float MaxElevation = 30.f;
};
