// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankMovementComponent : public UNavMovementComponent
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = Movement)
    void SetTankTracks(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

    UFUNCTION(BlueprintCallable, Category = Movement)
    void IntendMoveForward(float Throttle);

    UFUNCTION(BlueprintCallable, Category = Movement)
    void IntendTurnRight(float Throttle);

    UTankTrack* LeftTrack = nullptr;
    UTankTrack* RightTrack = nullptr;
};
