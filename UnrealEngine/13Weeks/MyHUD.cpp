// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

void AMyHUD::DrawHUD() 
{
	Super::DrawHUD();
//	DrawText("Greetings from Unreal!", FLinearColor::White, 80, 80, hudFont, 1.0, false);
	for (int c = messages.Num() - 1; c >= 0; c--) {
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f * pad;
		float x = 0.f;
		float y = c * messageH;
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		if (messages[c].time < 0) {
			messages.RemoveAt(c);
		}
	}
}

void AMyHUD::addMessage(Message msg) 
{
	messages.Add(msg);
}