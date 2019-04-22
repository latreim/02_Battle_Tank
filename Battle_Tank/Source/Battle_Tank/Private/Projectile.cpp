// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));
    PrimaryActorTick.bCanEverTick = true;
    ProjectileMovement->bAutoActivate = false;
}

void AProjectile::LaunchProjectile(float Speed)
{
    auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%f - Projectile Firing at: %f!"), Time, Speed);
    ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
    ProjectileMovement->Activate();
}

