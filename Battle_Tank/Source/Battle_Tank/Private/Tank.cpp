// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
// Sets default values
ATank::ATank()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
    
    TankAimingComponent->SetBarrelComponent(BarrelToSet);
    Barrel = BarrelToSet;
}
void ATank::SetTurretReference(UTankTurret* TurretToSet) {

    TankAimingComponent->SetTurretComponent(TurretToSet);
}
void ATank::Fire()
{
    if (!Barrel) { return; }
    GetWorld()->SpawnActor<AProjectile>(
        ProjectileBlueprint,
        Barrel->GetSocketLocation(FName("Projectile")),
        Barrel->GetSocketRotation(FName("Projectile"))
        );
    auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%f - Firing Canon!"), Time);

}
void ATank::AimAt(FVector HitLocation)
{
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);    
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

