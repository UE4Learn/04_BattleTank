// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire when ready
		ControlledTank->Fire(); // TODO: Limit firing rate
	}
}