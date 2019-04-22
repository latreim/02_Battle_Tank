// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::SetBarrelComponent(UTankBarrel* BarrelToSet) {
    
    Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretComponent(UTankTurret* TurretToSet) {
    Turret = TurretToSet;
}
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{    
    if (!Barrel) { return; }

    FVector OutLaunchVelocity(0);
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
    auto bAimAt = UGameplayStatics::SuggestProjectileVelocity(
        this,
        OutLaunchVelocity,
        StartLocation,
        HitLocation,
        LaunchSpeed,
        false, 
        0,
        0,
        ESuggestProjVelocityTraceOption::DoNotTrace);

    if (bAimAt)
    {
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(AimDirection);
        MoveTurretTowards(AimDirection);
    }    
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
    
    if (!Barrel) { return; }
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();

    auto AimAsRotator = AimDirection.Rotation();

    auto DeltaRotator = AimAsRotator - BarrelRotator;

    Barrel->Elevate(DeltaRotator.Pitch);
       
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection) {
    if (!Turret) { return; }
    auto TurretRotator = Turret->GetForwardVector().Rotation();

    auto AimAsRotator = AimDirection.Rotation();

    auto DeltaRotator = AimAsRotator - TurretRotator;
    Turret->Rotate(DeltaRotator.Yaw);
}



