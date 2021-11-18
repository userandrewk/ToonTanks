// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "Tower.h"
#include "Tank.h"
#include "ToonTanksPlayerController.h"


void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	if(Tank)
	{
		PlayerController = Cast<AToonTanksPlayerController>(Tank->GetTankPlayerController());
		
	}

	
	
}



void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if(DeadActor == Tank)
	{
		Tank->HandleDestruction();

		if(PlayerController)
		{
			PlayerController->SetPlayerEnabledState(false);
		}
	}
	else if(auto DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
}

