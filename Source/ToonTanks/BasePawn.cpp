// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"


#include "Kismet/GameplayStatics.h"
#include "Projectile.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	RootComponent = CapsuleComponent;

	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
	BaseMeshComponent->SetupAttachment(RootComponent);

	TurretMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Turret Mesh");
	TurretMeshComponent->SetupAttachment(BaseMeshComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>("Projectile Spawn Point");
	ProjectileSpawnPoint->SetupAttachment(TurretMeshComponent);

	
	
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

void ABasePawn::RotateTurret(FVector TargetRotation)
{
	TargetRotation = TargetRotation - TurretMeshComponent->GetComponentLocation();
	
	FRotator TargetRotator = FRotator::ZeroRotator;
	TargetRotator.Yaw = TargetRotation.Rotation().Yaw;

	TurretMeshComponent->SetWorldRotation(TargetRotator);
	
}

void ABasePawn::Fire()
{
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
		DefaultProjectileClass,
		ProjectileSpawnPoint->GetComponentLocation(),
		ProjectileSpawnPoint->GetComponentRotation());
	
	if(ProjectileLaunchSound){
		UGameplayStatics::PlaySoundAtLocation(this, ProjectileLaunchSound, ProjectileSpawnPoint->GetComponentLocation());
	}
	
	Projectile->SetOwner(this);
}

void ABasePawn::HandleDestruction()
{
	if(DeathParticleSystem)
	{
		if (DeathSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
		}

		if(DeathCameraShakeClass)
		{
			GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
		}
		
		UGameplayStatics::SpawnEmitterAtLocation(
			this,
			DeathParticleSystem,
			GetActorLocation(),
			GetActorRotation());
	}
	
}


