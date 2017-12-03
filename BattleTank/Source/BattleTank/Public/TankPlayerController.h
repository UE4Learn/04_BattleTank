// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Aim tank barrel to crosshair projection vector
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	float CrossHairXLocation = .5f;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	float CrossHairYLocation = .45f;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	float LineTraceRange = 1000000.f;

	// Get the location in world space of crosshair reticle
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection, FVector& CameraWorldLocation) const;

	// trace for visibility to get target to shoot
	bool GetLookVectorHitLocation(FVector CameraWorldLocation, FVector LookDirection, FVector& HitLocation) const;
};
