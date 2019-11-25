// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GEngine->AddOnScreenDebugMessage(-2, 10.f, FColor::Blue, "MyCharacter created!");

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	TMap<FString, int> map;
	map.Add("MyCharacter", 1);
	map.Add("MyNPC", 2);
	map.Add("MyNPC2", 3);
	int cnt = 0;
	for (TMap<FString, int>::TIterator it = map.CreateIterator(); it; ++it) {
		GEngine->AddOnScreenDebugMessage(cnt++, 10.f, FColor::Red, it->Key + ": " + FString::FromInt(it->Value));
	}
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Forward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("Right", this, &AMyCharacter::MoveRight);
	InputComponent->BindAxis("Yaw", this, &AMyCharacter::Yaw);
	InputComponent->BindAxis("Pitch", this, &AMyCharacter::Pitch);
}

void AMyCharacter::MoveForward(float amount) 
{
	if (Controller && amount) 
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}

void AMyCharacter::MoveRight(float amount) 
{
	if (Controller && amount) 
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}

void AMyCharacter::Yaw(float amount)
{
	AddControllerYawInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::Pitch(float amount)
{
	AddControllerPitchInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}