// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class ENDP1_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class USphereComponent* sphereCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class UStaticMeshComponent* sphereMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class UProjectileMovementComponent* projMovement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly);
	float destroyTime;
	UPROPERTY(BlueprintReadOnly)
	FVector Size;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void HandleHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, FVector normalImpulse, const FHitResult& hit);
	
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};
