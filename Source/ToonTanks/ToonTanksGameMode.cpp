// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "Tower.h"
#include "Tank.h"
#include "ToonTanksPlayerController.h"


void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
	
}


void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	
	if(DeadActor == Tank)
	{
		Tank->HandleDestruction();

		if(PlayerController)
		{
			PlayerController->SetPlayerEnabledState(false);
			EndGame(false);
		}
	}
	else if(ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		GameScore++;
		DestroyedTower->HandleDestruction();
		if(TowersNum <= 0)
		{
			EndGame(true);
		}
		
		
	}
}

void AToonTanksGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	PlayerController = Cast<AToonTanksPlayerController>(
			UGameplayStatics::GetPlayerController(this, 0));

	StartGame();
		
	if(PlayerController)
	{
		PlayerController->SetPlayerEnabledState(false);

		FTimerHandle GameStartTimer;

		FTimerDelegate GameStartTimerDelegate = FTimerDelegate::CreateUObject(
			PlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true);

		GetWorldTimerManager().SetTimer(GameStartTimer, GameStartTimerDelegate, StartDelay, false);
	}
}

