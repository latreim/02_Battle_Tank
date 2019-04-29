// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::SetTankTracks(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throttle) {
    if (!LeftTrack || !RightTrack) { return; }
    LeftTrack->SetThrottle(Throttle);
    RightTrack->SetThrottle(Throttle);
}

void UTankMovementComponent::IntendTurnRight(float Throttle) {
    if (!LeftTrack || !RightTrack) { return; }
    Throttle = Throttle * 1.5; // TODO, fix workaround.
    LeftTrack->SetThrottle(Throttle);
    RightTrack->SetThrottle(-Throttle);
}

