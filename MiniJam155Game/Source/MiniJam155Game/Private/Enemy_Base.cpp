// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Base.h"

#include "EnemyAIController.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AEnemy_Base::AEnemy_Base()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = AEnemyAIController::StaticClass();

	PawnMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
}

/*
void AEnemy_Base::FindSpawn()
{
	FVector RandomLocation;
	UNavigationSystemV1::K2_GetRandomLocationInNavigableRadius(this, UGameplayStatics::GetPlayerController(this, 0)->K2_GetActorLocation(), RandomLocation, 800); //TODO: Change to use variable instead of hard coded.

	FVector2d _ScreenPosition;
	if(!UGameplayStatics::ProjectWorldToScreen(UGameplayStatics::GetPlayerController(this, 0), RandomLocation, _ScreenPosition))
	{
		SetActorLocation(RandomLocation);
	}
}
*/