// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include "Actors/BaseRifle.h"
#include "ENDP1/ENDP1.h"
#include "Both/CharacterAnimation.h"
#include "Blueprint/UserWidget.h"
#include "HealthComponent.h"
ABasePlayer::ABasePlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	Cam = CreateDefaultSubobject<UCameraComponent>("Camera");
	Cam->SetupAttachment(SpringArm);

	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0, 90.0f));
	SpringArm->TargetArmLength = 300;
	SpringArm->bUsePawnControlRotation = true;
}
void ABasePlayer::Att()
{
	if (weaponObject->Attack())
	{
		ABPAnim->FireAnimationWindow();
	}
}
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* pc = Cast<APlayerController>(GetController());
	if (pc)
	{

		HUDReference = Cast<UPlayerHUD>(CreateWidget<UUserWidget>(pc, HUDClass));
		if (HUDReference)
		{
			HUDReference->AddToViewport();

			healthComp->COnHurt.AddDynamic(HUDReference, &UPlayerHUD::SetHealth);
			healthComp->COnDeath.AddDynamic(HUDReference, &UPlayerHUD::SetHealth);
		}
		else
		{
			UE_LOG(Game, Log, TEXT("Invalid HUD class"));
			Destroy();

		}

	}
	else
	{
		UE_LOG(Game, Log, TEXT("Failed to find controller"));
		Destroy();

	}
}
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ABasePlayer::Att);
	PlayerInputComponent->BindAxis("Turn Right", this, &ABasePlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up", this, &ABasePlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Move Forward", this, &ABasePlayer::InputAxisMoveForward);
	PlayerInputComponent->BindAxis("Move Horizontal", this, &ABasePlayer::InputAxisMoveHorizontal);
}

void ABasePlayer::InputAxisMoveForward(float _axisValue)
{
	AddMovementInput(FRotator(0, GetControlRotation().Yaw, 0).Vector(), _axisValue);
}

void ABasePlayer::InputAxisMoveHorizontal(float _axisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::Y), _axisValue);

}
