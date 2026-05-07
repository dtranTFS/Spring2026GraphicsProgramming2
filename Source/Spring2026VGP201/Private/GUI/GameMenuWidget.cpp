// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/GameMenuWidget.h"
#include "Kismet/KismetSystemLibrary.h"

void UGameMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateHealthBar(1.0f);
	UpdateScore(0);
	UpdateTimer(60);
	QuitButton->OnClicked.AddDynamic(this, &UGameMenuWidget::OnQuitClicked);
}

void UGameMenuWidget::UpdateHealthBar(float HealthPercent)
{
	if(!HealthBar)
	{
		return;
	}

	HealthBar->SetPercent(HealthPercent);
}

void UGameMenuWidget::UpdateScore(int Score)
{
	if(!ScoreText)
	{
		return;
	}
	FString ScoreString = FString::Printf(TEXT("Score: %d"), Score);
	ScoreText->SetText(FText::FromString(ScoreString));
}

void UGameMenuWidget::UpdateTimer(int Time)
{
	if(!TimerText)
	{
		return;
	}
	FString TimerString = FString::Printf(TEXT("Time: %d"), Time);
	TimerText->SetText(FText::FromString(TimerString));
}

void UGameMenuWidget::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}
