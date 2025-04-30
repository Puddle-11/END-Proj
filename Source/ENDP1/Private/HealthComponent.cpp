// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "ENDP1/ENDP1.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	currentHealth = maxHealth;
	AActor* Owner = GetOwner();
	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleDamage);
	}
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::HandleDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	currentHealth = FMath::Clamp(currentHealth - Damage, 0.0f, maxHealth);
	if (currentHealth > 0)
	{
		UE_LOG(Game, Log, TEXT("Health Decremented"));

		float healthPercent = currentHealth / maxHealth;

		COnHurt.Broadcast(healthPercent);
	}
	else
	{
		COnDeath.Broadcast(0.0f);
		//dead
	}
}

