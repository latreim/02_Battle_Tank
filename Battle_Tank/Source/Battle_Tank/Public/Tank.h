// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankMovementComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();


    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* BarrelToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference(UTankTurret* TurretToSet);

    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void AimAt(FVector HitLocation);    

protected:

    UTankAimingComponent* TankAimingComponent;
    UPROPERTY( BlueprintReadOnly )
    UTankMovementComponent* TankMovementComponent;
private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float ReloadTimeInSeconds = 3;
    
    UPROPERTY(EditAnywhere, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;

    UTankBarrel* Barrel = nullptr;

    double LastFireTime = 0;
};
