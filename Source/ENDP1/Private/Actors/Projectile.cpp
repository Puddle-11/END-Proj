// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "ENDP1/ENDP1.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile() : destroyTime(30), Size(0.18f, 0.18f, 0.18f)
{
 //	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	sphereCollider = CreateDefaultSubobject<USphereComponent>("Sphere Collision");
	sphereCollider->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));

	//sphereCollider->OnComponentHit.AddDynamic(this, &AProjectile::HandleHit);
	sphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::HandleBeginOverlap);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	SetRootComponent(sphereCollider);
	sphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("Sphere Mesh");
	sphereMesh->SetCollisionProfileName("NoCollision");
	sphereMesh->SetRelativeScale3D(Size);
	sphereMesh->SetStaticMesh(Asset.Object);
	sphereMesh->SetupAttachment(sphereCollider);

	projMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile movement");
	projMovement->ProjectileGravityScale = 0;

	projMovement->InitialSpeed = 1000;
	projMovement->MaxSpeed  = 1000;


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle projTimer;
	GetWorld()->GetTimerManager().SetTimer(projTimer, this, &AProjectile::K2_DestroyActor, destroyTime);

}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::HandleHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, FVector normalImpulse, const FHitResult& hit)
{
	UE_LOG(Game, Log, TEXT("Hello"));
	this->K2_DestroyActor();
}

void AProjectile::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(Game, Warning, TEXT("Overlap was called"));
	UE_LOG(Game, Warning, TEXT("Actor Name is: %s"), *OtherActor->GetName());
	this->K2_DestroyActor();
}

