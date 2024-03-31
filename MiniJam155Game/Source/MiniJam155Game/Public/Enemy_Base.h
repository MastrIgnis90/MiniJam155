// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy_Base.generated.h"

class UFloatingPawnMovement;
class USphereComponent;

UCLASS()
class MINIJAM155GAME_API AEnemy_Base : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy_Base();

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess="True"))
	TObjectPtr<UFloatingPawnMovement> PawnMovementComponent;
};
