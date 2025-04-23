// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseRifle.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ABaseRifle::ABaseRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

	rifleMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	rifleMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABaseRifle::BeginPlay()
{
	Super::BeginPlay();
	AActor* act = this;
	ParentPawn = Cast<APawn>(act);

}

// Called every frame
void ABaseRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseRifle::Attack()
{
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = ParentPawn->GetController();
	SpawnParams.Instigator = ParentPawn; // If firing from a pawn

	GetWorld()->SpawnActor<AActor>(projClass, SpawnLocation, SpawnRotation, SpawnParams);
}

