// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MINIJAM155GAME_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	AEnemyAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;
};
