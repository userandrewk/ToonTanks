// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

#define OUT

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = Cast<APlayerController>(GetController());
}

void ATank::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(PlayerController)
	{
		PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, OUT HitResult);	

		DrawDebugSphere(GetWorld(),
			HitResult.Location,
			15.f,
			20,
			FColor::Red);

		TurnTurret(HitResult.Location);
	}
	
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	InputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
	InputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
	
}

void ATank::Move(float Value)
{
	FVector Offset;

	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	
	Offset.X = Value * TankSpeed * DeltaTime ;
	
	AddActorLocalOffset(Offset, true);
}

void ATank::Turn(float Value)
{
	FRotator Rotate;

	Rotate.Yaw = Value * TankTurnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	
	AddActorLocalRotation(Rotate, true);
	
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();

	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
}

