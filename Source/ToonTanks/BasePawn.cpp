// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"	


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>("Projectile Spawn Point");
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

	PlayerNickname = TEXT("default");
	
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasePawn::TurnTurret(FVector TargetVector)
{
	FVector TargetRotation = TargetVector - TurretMesh->GetComponentLocation();
	FRotator TargetRotator(0.f, TargetRotation.Rotation().Yaw, 0.f);
	
	TurretMesh->SetWorldRotation(TargetRotator);
}

void ABasePawn::Fire()
{
	DrawDebugSphere(GetWorld(),
		ProjectileSpawnPoint->GetComponentLocation(),
		40.f,
		6,
		FColor::Red,
		false,
		2.f);

	//Spawn Projectile
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileUClass,
		ProjectileSpawnPoint->GetComponentLocation(),
		ProjectileSpawnPoint->GetComponentRotation());

	Projectile->SetOwner(this);
}


void ABasePawn::HandleDestruction()
{
	// Visual / sound
}


