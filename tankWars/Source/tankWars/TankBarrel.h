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
		UPROPERTY(EditAnywhere, Category = Setup)
		float MaxSpeedPerSecond = 15.f;
		
		UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0.f;

		UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 30.f;
};