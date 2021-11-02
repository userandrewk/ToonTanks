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

	
	
	protected:
	//Member variables

	//Member features
	virtual void BeginPlay() override; //when game start

	
	private:
	//Member variables


	//Member features

};
