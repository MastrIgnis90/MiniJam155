// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "Enemy_Base.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

AEnemyAIController::AEnemyAIController()
{
	BrainComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(InPawn->IsA(AEnemy_Base::StaticClass()))
	{
		RunBehaviorTree(LoadObject<UBehaviorTree>(nullptr, TEXT("/Game/AI/BT_Enemy")));
	}


}
