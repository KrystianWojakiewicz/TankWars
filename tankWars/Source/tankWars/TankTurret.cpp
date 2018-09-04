// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

FRotator UTankTurret::Rotate(float Speed) {

	float ClampedSpeed = FMath::Clamp<float>(Speed, -1, 1);

	float DeltaRotation = ClampedSpeed * MaxSpeedPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = RelativeRotation.Yaw + DeltaRotation;

	this->SetRelativeRotation(FRotator(0, NewRotation, 0));

	return RelativeRotation;
}

