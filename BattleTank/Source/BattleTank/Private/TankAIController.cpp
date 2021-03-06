// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards player

	if (!ensure(ControlledTank->FindComponentByClass<UTankAimingComponent>())) { return; }

	UTankAimingComponent* AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// If locked, fire
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
	AimingComponent->Fire(); // TODO: Limit firing rate
	}
}