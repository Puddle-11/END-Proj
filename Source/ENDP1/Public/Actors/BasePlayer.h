// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "Both/PlayerHUD.h"
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
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> HUDClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPlayerHUD* HUDReference;


protected:
	class USpringArmComponent* SpringArm;
	class UCameraComponent* Cam;
private:
	void Att();
	void InputAxisMoveForward(float _axisValue);
	void InputAxisMoveHorizontal(float _axisValue);
};
