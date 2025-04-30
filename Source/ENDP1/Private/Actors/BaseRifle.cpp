// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseRifle.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "ENDP1/ENDP1.h"

// Sets default values
ABaseRifle::ABaseRifle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Default Scene");
	rifleMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	rifleMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABaseRifle::BeginPlay()
{
	Super::BeginPlay();

	APawn* CastedPawn = Cast<APawn>(GetParentActor());

	if (CastedPawn)
	{
		ParentPawn = CastedPawn;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("bruh"));
		Destroy();
	}
}

// Called every frame
void ABaseRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ABaseRifle::Attack()
{
	bool res = CanAttack();
	if (res)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = ParentPawn->GetController();
		SpawnParams.Instigator = ParentPawn;


		FVector pos = rifleMesh->GetSocketLocation(muzzleSocketName);
		FRotator rot = ParentPawn->GetBaseAimRotation();

		FTimerHandle TimerHandle;
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUObject(this, &ABaseRifle::SetAttack);
		actionHappening = true;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, cooldown, false);

		GetWorld()->SpawnActor<AActor>(projClass, pos, rot, SpawnParams);
	}
	return res;
}


bool ABaseRifle::CanAttack()
{
	return !actionHappening;
}
void ABaseRifle::SetAttack()
{
	actionHappening = false;
}


