// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/CharacterAnimation.h"
#include "KismetAnimationLibrary.h"

void UCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds) 
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	APawn* pawn = TryGetPawnOwner();
	if (pawn != nullptr)
	{
		FVector vel = pawn->GetVelocity();
		Velocity = vel.Size();


		//Valid
		FRotator actorRotation = pawn->GetActorRotation();
		Direction = UKismetAnimationLibrary::CalculateDirection(vel, actorRotation);
	}
	else
	{
		//Invalid
	}
		PreviewWindowUpdate();
}

void UCharacterAnimation::PreviewWindowUpdate()
{
	if (debugFiring)
	{
		FireAnimationWindow();
		debugFiring = false;
	}
}

void UCharacterAnimation::FireAnimationWindow()
{
	PlaySlotAnimationAsDynamicMontage(fireIronSight, slotName);
}

