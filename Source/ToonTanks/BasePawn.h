// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float GetHealth() {return Health;}

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fire();

	void RotateTurret(FVector TargetRotation);

	
	UPROPERTY(EditAnywhere, Category="Combat")
	float Health;


private:
	//Variables
	
	UPROPERTY(VisibleAnywhere, Category="Pawn Core Setup")
	UCapsuleComponent* CapsuleComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Pawn Core Setup")
	UStaticMeshComponent* BaseMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Pawn Core Setup")
	UStaticMeshComponent* TurretMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Pawn Core Setup")
	USceneComponent* ProjectileSpawnPoint = nullptr;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TSubclassOf<class AProjectile> DefaultProjectileClass;

	UPROPERTY(EditAnywhere, Category="Animation")
	class UParticleSystem* DeathParticleSystem = nullptr;

	UPROPERTY(EditAnywhere, Category="Animation")
	USoundBase* ProjectileLaunchSound = nullptr;
	
	UPROPERTY(EditAnywhere, Category="Animation")
	class USoundBase* DeathSound = nullptr;

	UPROPERTY(EditAnywhere, Category="Animation")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
	

	
	//Feature

	void TurnTurret();
	
	void Destruction();

	
	
};
