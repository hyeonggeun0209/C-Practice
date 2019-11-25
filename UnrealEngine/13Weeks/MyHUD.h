// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

struct Message {
	FString message;
	float time;
	FColor color;
	Message() {
		time = 5.f;
		color = FColor::White;
	}
	Message(FString iMessage, float iTime, FColor iColor) {
		message = iMessage;
		time = iTime;
		color = iColor;
	}
};
/**
 * 
 */
UCLASS()
class MYVIEW_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:
	// Fonts are used to display strings in the HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	UFont* hudFont;

	// Function to display HUD on screen
	virtual void DrawHUD() override;
	
	TArray<Message> messages;
	void addMessage(Message msg);
};
