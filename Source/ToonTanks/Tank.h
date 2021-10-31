// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()


	public:
	
	ATank();

	//Variables
	UPROPERTY(EditAnywhere, Category="Tank Setup", BlueprintReadWrite)
	float TankSpeed = 800.f;
	
	UPROPERTY(EditAnywhere, Category="Tank Setup", BlueprintReadWrite)
	float TankTurnSpeed = 80.f;

	//Features
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaSeconds) override;

	void HandleDestruction();

	APlayerController* GetPlayerController(){ return PlayerController;}

	protected:
	
	//Variables
	virtual void BeginPlay() override;
	
	private:

	//Variables
	UPROPERTY(VisibleAnywhere, Category = "Tank Setup")
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, Category= "Tank Setup")
	class UCameraComponent* Camera = nullptr;

	APlayerController* PlayerController = nullptr ;

	FHitResult HitResult ;

	// Features
	void Move(float Value);
	
	void Turn(float Value);
	
};
