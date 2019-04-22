// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay() {

    Super::BeginPlay();

    if (GetControlledTank())
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Controller is possessing: %s"), *(GetControlledTank()->GetName()));
    }
}

void ATankAIController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    if (GetPlayerTank())
    {
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::AimTowardsPlayer()
{
}
