// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

    void BeginPlay() override;

    void Tick(float DeltaTime) override;

private:
    ATank* GetControlledTank() const;

    // Start Tank Barrel Move towards crosshair to World intersection
    void AimTowardsCrossHair();

    bool GetSightRayHitLocation(FVector& OutHitLocation) const;

    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

    bool GetVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

    UPROPERTY( EditAnywhere )
    float CrossHairXLocation = 0.5f;

    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.33333f;

    UPROPERTY(EditAnywhere)
    float Distance = 1000000.f;

};
