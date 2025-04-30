// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Agent.h"
#include "Actors/BaseRifle.h"
#include "Actors/BaseRifle.h"
#include "Both/CharacterAnimation.h"
// Sets default values
AAgent::AAgent()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}
void AAgent::PostLoad() 
{
	Super::PostLoad();
	class USkeletalMeshComponent* meshComp;

	class UMaterialInstanceDynamic* materialInstance;

    meshComp = GetMesh();

    materialInstance = meshComp->CreateAndSetMaterialInstanceDynamic(0);

    materialInstance->SetVectorParameterValue(FName("Tint"), tintCol);

}

// Called when the game starts or when spawned
void AAgent::BeginPlay()
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
void AAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (weaponObject->Attack())
    {
        ABPAnim->FireAnimationWindow();
    }


}

