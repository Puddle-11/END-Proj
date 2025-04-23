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
public:
	void NativeUpdateAnimation(float DeltaSeconds) override;
};
