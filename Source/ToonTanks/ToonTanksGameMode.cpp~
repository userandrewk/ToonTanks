// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanksPlayerController.h"
#include "TimerManager.h"

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
	else if(ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
	
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

    HandleGameStart();

	
	
}

void AToonTanksGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	PlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if(PlayerController)
	{
		PlayerController->SetPlayerEnabledState(false);	
		FTimerHandle PlayerEnableTimerHandle;

		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(PlayerController,
		&AToonTanksPlayerController::SetPlayerEnabledState,
		true);

		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
		TimerDelegate,
		GameStartDelay,
		false);
	}

	
		
}