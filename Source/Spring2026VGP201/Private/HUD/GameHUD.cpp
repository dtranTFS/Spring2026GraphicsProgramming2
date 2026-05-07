// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/GameHUD.h"
#include "Widgets/SWeakWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("GameHUD BeginPlay"));

	// 2. Slate method of making UI
	// ShowSettingsWidget();

	// 3. UMG method of making UI
	SpawnGameMenuWidget();
}

void AGameHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;

	// Canvas Dimensions
	float CanvasWidth = Canvas->ClipX;
	float CanvasHeight = Canvas->ClipY;
	FVector2D Center(CanvasWidth * 0.5f, CanvasHeight * 0.5f);

	// Crosshair Dimensions
	float CrosshairWidth = CrosshairTexture->GetSurfaceWidth();
	float CrosshairHeight = CrosshairTexture->GetSurfaceHeight();

	float AlignmentX = 0.5;
	float AlignmentY = 0.5;
	FVector2D CrosshairPosOffset(CrosshairWidth * AlignmentX, CrosshairHeight * AlignmentY);

	// Draw Settings
	FVector2D FinalCrosshairPos = Center - CrosshairPosOffset;

	float CrosshairScale = 5.0f;
	FVector2D FinalCrosshairSize(CrosshairWidth * CrosshairScale, CrosshairHeight * CrosshairScale);

	// Draw the crosshair
	FCanvasTileItem TileItem(FinalCrosshairPos, CrosshairTexture->GetResource(), FinalCrosshairSize, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

void AGameHUD::SpawnGameMenuWidget()
{
	// Delete game menu widget if it already exists
	if (GameMenuWidgetContainer) {
		GameMenuWidgetContainer->RemoveFromParent();
		GameMenuWidgetContainer = nullptr;
	}

	GameMenuWidgetContainer = CreateWidget<UGameMenuWidget>(GetWorld(), GameMenuWidgetClass);
	GameMenuWidgetContainer->AddToViewport();

	PlayerOwner->bShowMouseCursor = false;
	PlayerOwner->SetInputMode(FInputModeGameOnly());
}

void AGameHUD::ShowSettingsWidget() {
	SettingsWidget = SNew(SSettingsWidget).GameHUD(this).MyInt(6548);
	GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(SettingsWidgetContainer, SWeakWidget).PossiblyNullContent(SettingsWidget.ToSharedRef()));

	PlayerOwner->bShowMouseCursor = true;
	PlayerOwner->SetInputMode(FInputModeUIOnly());
}

void AGameHUD::HideSettingsWidget() {
	GEngine->GameViewport->RemoveViewportWidgetContent(SettingsWidgetContainer.ToSharedRef());

	PlayerOwner->bShowMouseCursor = false;
	PlayerOwner->SetInputMode(FInputModeGameOnly());
}