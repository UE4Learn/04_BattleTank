// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
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

private:

	ATank* GetControlledTank() const;

	// Aim tank barrel to crosshair projection vector
	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere, Category = "Widgets")
	float CrossHairXLocation = .5f;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	float CrossHairYLocation = .45f;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	float LineTraceRange = 1000000.f;

	// Get the location in world space of crosshair reticle
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection, FVector& CameraWorldLocation) const;

	// trace for visibility to get target to shoot
	bool GetLookVectorHitLocation(FVector CameraWorldLocation, FVector LookDirection, FVector& HitLocation) const;
};
