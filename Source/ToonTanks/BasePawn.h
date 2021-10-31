// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawm Setup")
	FString PlayerNickname;

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TurnTurret(FVector TargetVector);

	void Fire();

	UPROPERTY(VisibleAnywhere, Category="Pawn Setup")
	class UCapsuleComponent* CapsuleComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Pawn Setup")
	UStaticMeshComponent* BaseMesh = nullptr;

	UPROPERTY(VisibleAnywhere,Category="Pawn Setup")
	UStaticMeshComponent* TurretMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Pawn Setup", BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint = nullptr;
	

private:
	// Member variable
	

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TSubclassOf<class AProjectile> ProjectileUClass;


};
