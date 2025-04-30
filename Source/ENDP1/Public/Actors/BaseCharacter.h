// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class ENDP1_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapons");
	class TSubclassOf<AActor> weaponClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class UChildActorComponent* ChildActorComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class ABaseRifle* weaponObject;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class UCharacterAnimation* ABPAnim;
	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	class UHealthComponent* healthComp;
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
