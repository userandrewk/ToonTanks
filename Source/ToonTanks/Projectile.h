// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//Member variables
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Projectile Setup")
	class UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UPROPERTY(EditAnywhere, Category="Combat", BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
	float Damage = 25.f;

	UPROPERTY(EditAnywhere, Category="Combat", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float ProjectileMaxSpeed = 4000.f;

	UPROPERTY(EditAnywhere, Category="Combat", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float ProjectileInitSpeed = 3000.f;

	//Member feature
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		FVector NormalImpulse, const FHitResult& HitResult);
};
