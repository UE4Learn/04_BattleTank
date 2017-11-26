// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// -1 is max downward movement and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 10.f;

	UPROPERTY(meta = (ClampMin = 0.f, ClampMax = 40.f), EditAnywhere, Category = "Setup")
	float MaxElevationDegrees = 40.f;

	UPROPERTY(meta = (ClampMin = 0.f, ClampMax = 0.f), EditAnywhere, Category = "Setup")
	float MinElevationDegrees = 0.f;
};
