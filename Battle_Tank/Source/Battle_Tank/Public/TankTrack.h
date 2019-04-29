// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = Movement)
    void SetThrottle(float Throttle); //TODO Clamp Throttle between -1 and +1

    // Max force per track in Newtons
    UPROPERTY(EditDefaultsOnly)
    float TrackMaxDrivingForce = 40000000.0f; // Assuming 40 tonne tank and 1g accelaration
};
