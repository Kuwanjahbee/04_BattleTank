// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	//Start the tank moving the barrel so that a shot would hit where 
	//the crosshair intersects world.
	void AimTowardsCrosshair();

	//Return an Out Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	
};
