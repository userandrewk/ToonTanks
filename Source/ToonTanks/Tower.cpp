// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
	Health = 100.f; // Default value for tower
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	TowerLocation = GetOwner()->GetActorLocation();

	PlayerTank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//Setup timer to fire

	
}


void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(InRange())
	{
		FVector TargetLocation = PlayerTank->GetActorLocation();
		RotateTurret(TargetLocation);
	}
}

const bool ATower::InRange()
{
	if(PlayerTank)
	{
		float DistanceToTank = FVector::Dist(TowerLocation, PlayerTank->GetActorLocation());

		if(DistanceToTank <= TowerRange)
		{
			return true;
		}
		
	}
	return false;
}




