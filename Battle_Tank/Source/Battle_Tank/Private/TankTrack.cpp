// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {    

    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

    RootComponent->AddForceAtLocation(ForceApplied, ForceLocation);

    //auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%s Is Throttling with a force of: %f!"), *GetName(), Throttle);
}

