// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MyTankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKWARS_API AMyTankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;

private:

	ATank * GetControlledTank() const;
	ATank* GetPlayerTank() const;
};
