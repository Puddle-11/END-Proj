// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ProgressBar.h"
#include "Both/PlayerHUD.h"
void UPlayerHUD::SetHealth(float health)
{
	HealthBar->SetPercent(health);
}
