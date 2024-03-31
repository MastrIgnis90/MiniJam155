// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MyWorldSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MINIJAM155GAME_API UMyWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	void SpawnWave();

private:
	FTimerHandle TimerHandle;
	TObjectPtr<ACharacter> PlayerCharacter;
	int SpawnRadius = 400;
	int SpawnInterval = 5;
};
