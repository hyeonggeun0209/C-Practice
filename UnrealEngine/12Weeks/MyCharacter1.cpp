// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter1.h"

// Sets default values
AMyCharacter1::AMyCharacter1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Forward", this, &AMyCharacter1::MoveForward);
	InputComponent->BindAxis("Right", this, &AMyCharacter1::MoveRight);
	InputComponent->BindAxis("Back", this, &AMyCharacter1::MoveBack);
	InputComponent->BindAxis("Left", this, &AMyCharacter1::MoveLeft);

}

void AMyCharacter1::MoveForward(float amount) 
{
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		// AddMovementInput을 호출해 실제로 플레이어를 'fwd' 방향으로 'amount' 만큼 이동시킴
		AddMovementInput(fwd, amount);
	}
}

void AMyCharacter1::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}

void AMyCharacter1::MoveBack(float amount)
{
	if (Controller && amount)
	{
		FVector back = GetActorForwardVector();
		AddMovementInput(back, amount);
	}
}

void AMyCharacter1::MoveLeft(float amount)
{
	if (Controller && amount)
	{
		FVector left = GetActorRightVector();
		AddMovementInput(left, amount);
	}
}

