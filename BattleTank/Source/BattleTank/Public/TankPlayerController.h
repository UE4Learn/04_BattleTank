// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	// Aim tank barrel to crosshair projection vector
	void AimTowardsCrosshair();

private:
	// Get the location in world space of crosshair reticle
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
