// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Actors/BaseRifle.h"
#include "Both/CharacterAnimation.h"
#include "HealthComponent.h"
// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
    ChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActorComponent"));

	healthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	ChildActorComponent->SetupAttachment(GetMesh(), TEXT("place_weapon_here"));

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	ChildActorComponent->SetChildActorClass(weaponClass);
    AActor* ChildActor = ChildActorComponent->GetChildActor();
    ABaseRifle* Rifle = Cast<ABaseRifle>(ChildActor);

    if (Rifle)
    {
        weaponObject = Rifle;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Weapon needed"));
        Destroy();
    }

    ABPAnim = Cast<UCharacterAnimation>(GetMesh()->GetAnimInstance());
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

