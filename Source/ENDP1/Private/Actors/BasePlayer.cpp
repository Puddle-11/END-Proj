// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <Kismet/KismetMathLibrary.h>

ABasePlayer::ABasePlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	Cam = CreateDefaultSubobject<UCameraComponent>("Camera");
	Cam->SetupAttachment(SpringArm);
	
	SpringArm->SetRelativeLocation(FVector(0.0f,0.0,90.0f));
	SpringArm->TargetArmLength = 205;
	SpringArm->bUsePawnControlRotation = true;
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Turn Right", this, &ABasePlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up", this, &ABasePlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Move Forward", this, &ABasePlayer::InputAxisMoveForward);
	PlayerInputComponent->BindAxis("Move Horizontal", this, &ABasePlayer::InputAxisMoveHorizontal);
}

void ABasePlayer::InputAxisMoveForward(float _axisValue)
{
	AddMovementInput(FRotator(0,GetControlRotation().Yaw, 0).Vector(), _axisValue);
}

void ABasePlayer::InputAxisMoveHorizontal(float _axisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::Y), _axisValue);

}
