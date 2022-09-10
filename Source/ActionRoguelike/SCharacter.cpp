// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spring_arm_comp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	spring_arm_comp->SetupAttachment(RootComponent);
	spring_arm_comp->bUsePawnControlRotation = true;

	camera_comp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	camera_comp->SetupAttachment(spring_arm_comp);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ASCharacter::PrimaryAttack);
}

void ASCharacter::MoveForward(float value)
{
	FRotator control_rotator = GetControlRotation();

	control_rotator.Pitch = 0.0f;
	control_rotator.Roll = 0.0f;

	AddMovementInput(control_rotator.Vector(), value);
}

void ASCharacter::MoveRight(float value)
{
	FRotator control_rotator = GetControlRotation();

	control_rotator.Pitch = 0.0f;
	control_rotator.Roll = 0.0f;

	FVector right_vector = FRotationMatrix(control_rotator).GetScaledAxis(EAxis::Y);

	AddMovementInput(right_vector, value);
}

void ASCharacter:: PrimaryAttack()
{
	FTransform SpawnTM = FTransform(GetControlRotation(), GetActorLocation());
	FActorSpawnParameters SpawnParam;
	SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParam);
}