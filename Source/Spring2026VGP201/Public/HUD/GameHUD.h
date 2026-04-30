// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "GUI/SlateExample/SSettingsWidget.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SPRING2026VGP201_API AGameHUD : public AHUD
{
	GENERATED_BODY()
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 1. HUD Draw method
	UPROPERTY(EditAnywhere)
	UTexture2D* CrosshairTexture;

	virtual void DrawHUD() override;

	// 2. Slates method of making UI
	TSharedPtr<class SSettingsWidget> SettingsWidget;
	TSharedPtr<class SWidget> SettingsWidgetContainer;

	void ShowSettingsWidget();
	void HideSettingsWidget();
};
