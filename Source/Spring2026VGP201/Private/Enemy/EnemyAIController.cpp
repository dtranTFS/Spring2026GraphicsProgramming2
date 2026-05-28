// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAIController.h"

AEnemyAIController::AEnemyAIController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if(!PawnSensing)
	{
		PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
		PawnSensing->OnSeePawn.AddDynamic(this, &AEnemyAIController::OnSeePawn);
	}
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(StartingBehaviorTree);
}

void AEnemyAIController::OnSeePawn(APawn* PlayerPawn)
{
	AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(PlayerPawn);
	if(!PlayerCharacter) return;

	SetCanSeePlayer(true, PlayerCharacter);

	RunRetriggerableTimer();
}

void AEnemyAIController::SetCanSeePlayer(bool bCanSee, UObject* PlayerObject)
{
	UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
	BlackboardComp->SetValueAsBool("CanSeePlayer", bCanSee);

	if (bCanSee) {
		BlackboardComp->SetValueAsObject("PlayerTarget", PlayerObject);
	}

}

void AEnemyAIController::RunRetriggerableTimer()
{
	GetWorldTimerManager().ClearTimer(CanSeePlayerTimerHandle);
	CanSeePlayerTimerDelegate.BindUFunction(this, FName("SetCanSeePlayer"), false, nullptr);
	GetWorldTimerManager().SetTimer(CanSeePlayerTimerHandle, CanSeePlayerTimerDelegate, PawnSensing->SensingInterval * 2.0f, false);
}