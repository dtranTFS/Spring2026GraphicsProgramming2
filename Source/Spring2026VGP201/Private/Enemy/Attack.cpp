// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Attack.h"

EBTNodeResult::Type UAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Method 1: Calling player hurt function directly
	// AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// PlayerCharacter->OnHurtPlayer(1.0f);

	// Method 2: Using Blackboard
	// AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("PlayerTarget"));
	// PlayerCharacter->OnHurtPlayer(5.0f);

	// Method 3: Using Character
	// AAIController* EnemyAIController = OwnerComp.GetAIOwner();
	// AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(EnemyAIController->GetPawn());
	// float DamageAmt = EnemyCharacter->Damage; // 10.0f
	// 
	// AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// PlayerCharacter->OnHurtPlayer(DamageAmt);

	// Method 4: Using built in damage system
	AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UGameplayStatics::ApplyDamage(PlayerCharacter, 20.0f, OwnerComp.GetAIOwner(), OwnerComp.GetAIOwner()->GetPawn(), UDamageType::StaticClass());

	return EBTNodeResult::Succeeded;
}
