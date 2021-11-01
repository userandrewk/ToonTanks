// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/CapsuleComponent.h"


ATower::ATower()
{
	
}


void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	

	if(bAlive)
	{
		if(InFireRange())
		{
			TurnTurret(Tank->GetActorLocation()); // turn turret to a tank direction
		}
	}
}


void ATower::BeginPlay()
{
	Super::BeginPlay();
	
	TowerLocation = GetOwner()->GetActorLocation();
	
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//Set auto-fire
	if(bAlive)
	{
		GetWorldTimerManager().SetTimer(FireRateTimer, this, &ATower::CheckFireCondition, FireRate, true);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(FireRateTimer);
	}
	
}

void ATower::CheckFireCondition()
{
	if(!bAlive)return;
	
	if(InFireRange())
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if(Tank)
	{
		float Distance = FVector::Dist(TowerLocation, Tank->GetActorLocation());

		if(Distance <= TowerRange)
		{
			return true;
		}
	}
	return false;
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();

	bAlive = false;
	GetOwner()->Destroy();
	
}

