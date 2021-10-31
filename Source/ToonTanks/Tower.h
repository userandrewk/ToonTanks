// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

	public:
	ATower();

	//Member variables 
	

	//Member feature
	virtual void Tick(float DeltaSeconds) override;

	void HandleDestruction();
	
	protected:
	//Member variables

	//Member features
	virtual void BeginPlay() override; //when game start

	
	private:
	//Member variables
	class ATank* Tank = nullptr;

	FVector TowerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category="Tower Setup")
	float TowerRange = 500.f;
	UPROPERTY(EditAnywhere, Category="Tower Setup")
	float FireRate = 1.f;

	FTimerHandle FireRateTimer;

	bool bAlive = true;

	//Member features
	void CheckFireCondition();

	bool InFireRange();
	
};
