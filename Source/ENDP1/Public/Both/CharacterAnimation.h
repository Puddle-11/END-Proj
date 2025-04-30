// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimation.generated.h"

/**
 * 
 */
UCLASS()
class ENDP1_API UCharacterAnimation : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
	float Velocity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
	float Direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	bool debugFiring;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	UAnimSequence* fireIronSight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FName slotName = "ActionSlotName";

public:
	void NativeUpdateAnimation(float DeltaSeconds) override;
	void PreviewWindowUpdate();
	void FireAnimationWindow();
};
