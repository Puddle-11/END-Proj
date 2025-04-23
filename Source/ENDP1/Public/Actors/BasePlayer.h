// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "BasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class ENDP1_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ABasePlayer();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	class USpringArmComponent* SpringArm;
	class UCameraComponent* Cam;
private:
	void InputAxisMoveForward(float _axisValue);
	void InputAxisMoveHorizontal(float _axisValue);
};
