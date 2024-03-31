// Fill out your copyright notice in the Description page of Project Settings.

#include "MyWorldSubsystem.h"
#include "Enemy_Base.h"
#include "Kismet/GameplayStatics.h"

bool UMyWorldSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UMyWorldSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{	
	PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UMyWorldSubsystem::SpawnWave, SpawnInterval, true);
}

void UMyWorldSubsystem::SpawnWave() 
{
	FVector PlayerPosition = PlayerCharacter->GetActorLocation();
	FVector SpawnVector = FVector(SpawnRadius, SpawnRadius, 0) + PlayerPosition;
	FRotator SpawnRotation = FRotator::MakeFromEuler(FVector(0, 0, FMath::RandRange(0, 360)));
	FVector SpawnPosition = SpawnRotation.RotateVector(SpawnVector);
	
	UE_LOG(LogTemp, Warning, TEXT("SpawnVector: %s"), *SpawnVector.ToString());
	UE_LOG(LogTemp, Warning, TEXT("SpawnPosition: %s"), *SpawnPosition.ToString());

	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActorAbsolute<AEnemy_Base>(SpawnPosition, FRotator::ZeroRotator, SpawnParameters);
}