// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

#define OUT

ATank::ATank()
{
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void ATank::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
}


