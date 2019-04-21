// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay() {

    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();

    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Controller not possessing a Pawn"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Controller is possessing: %s"), *(ControlledTank->GetName()));
    }
}

void ATankPlayerController::Tick(float DeltaTime) {

    Super::Tick(DeltaTime);

    AimTowardsCrossHair();
}

ATank* ATankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair() {

    if (!GetControlledTank()) { return; }

    FVector OutHitLocation;
    if (GetSightRayHitLocation(OutHitLocation)) // has side effect of line-tracing.
    {
        GetControlledTank()->AimAt(OutHitLocation);
        /// TODO Tell controlled tank to aim at that point
    }
}

// Get World location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {

    /// Find Crosshair position
    int32 ViewPortSizeX, ViewPortSizeY;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);
    auto ScreenLocation = FVector2D(ViewPortSizeX*CrossHairXLocation, ViewPortSizeY*CrossHairYLocation);
    
    FVector OutLookDirection;
    if (GetLookDirection(ScreenLocation, OutLookDirection))
    {
        GetVectorHitLocation(OutLookDirection, OutHitLocation);
    }

    return true;
}

//De-Project Screen position of the crosshair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const {

    FVector CameraWorldLocation; // to be discarded
    return DeprojectScreenPositionToWorld(
        ScreenLocation.X,
        ScreenLocation.Y,
        CameraWorldLocation,
        OutLookDirection
    );
}

bool ATankPlayerController::GetVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const {

    FHitResult OutHitResult;
    FVector LineStart = PlayerCameraManager->GetCameraLocation();
    FVector LineEnd = LineStart + LookDirection * Distance;

    auto LineTrace = GetWorld()->LineTraceSingleByChannel(
        OutHitResult,
        LineStart,
        LineEnd,
        ECollisionChannel::ECC_Visibility
    );
    if (LineTrace)
    {
        OutHitLocation = OutHitResult.Location;
        return LineTrace;
    }
    else {
        OutHitLocation = FVector(0);
        return LineTrace;
    }

}