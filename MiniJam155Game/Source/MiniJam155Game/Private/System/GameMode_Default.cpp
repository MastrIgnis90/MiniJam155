// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_Default.h"

AGameMode_Default::AGameMode_Default()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BPs/BP_PlayerCharacter"));
	if(PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
