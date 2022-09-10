// Fill out your copyright notice in the Description page of Project Settings.


#include "SMgicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphere_comp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = sphere_comp;

	effect_comp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	effect_comp->SetupAttachment(sphere_comp);

	movement_comp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	movement_comp->InitialSpeed = 1000.0f;
	movement_comp->bRotationFollowsVelocity = true;
	movement_comp->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

