// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/DelegateCombinations.h"
#include "BaseRifle.generated.h"

UCLASS()
class ENDP1_API ABaseRifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseRifle();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	APawn* ParentPawn;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
	TSubclassOf<AActor> projClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class USkeletalMeshComponent* rifleMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	AActor* ParentActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	FName muzzleSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	float cooldown = 5;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool actionHappening;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool Attack();
	bool CanAttack();
	void SetAttack();



	FTimerDelegate actionStopped;


};
