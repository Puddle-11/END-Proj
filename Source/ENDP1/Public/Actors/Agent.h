// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/BaseCharacter.h"

#include "Agent.generated.h"

UCLASS()
class ENDP1_API AAgent : public ABaseCharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAgent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor tintCol;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostLoad() override;
};
