// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

void UTankBarrel::Elevate(float Speed) {
	auto Time = GetWorld()->GetTimeSeconds();
	
	float ClampedSpeed = FMath::Clamp<float>(Speed, -1.f, +1.f);
	float ElevationChange = ClampedSpeed * MaxSpeedPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewElevation = RelativeRotation.Pitch + ElevationChange;

	float ClampedElevation = FMath::Clamp<float>(NewElevation, MinElevation, MaxElevation);
	this->SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}


