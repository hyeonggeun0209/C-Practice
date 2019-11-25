// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "MyHUD.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController) {
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());
		hud->addMessage(Message("Hello World! I am just created!", 5.f, FColor::Red));
	}
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

