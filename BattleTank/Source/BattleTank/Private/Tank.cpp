// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(ProjectileBlueprint))
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire failed: No projectile assigned to tank blueprint defaults."));
		return;
	}
	if (!ensure(Barrel)) { return; }
		bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
		if (isReloaded)
		{

			// Spawn projectile at the end of the barrel
			auto ProjectileSocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
			auto ProjectileSocketRotation = Barrel->GetSocketRotation(FName("Projectile"));

			auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, ProjectileSocketLocation, ProjectileSocketRotation);

			Projectile->LaunchProjectile(LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
		}
}
