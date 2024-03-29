// Fill out your copyright notice in the Description page of Project Settings.


#include "System/AssetManager_MiniJam155.h"

#include "System/GameplayTags.h"

UAssetManager_MiniJam155::UAssetManager_MiniJam155()
{
}

UAssetManager_MiniJam155& UAssetManager_MiniJam155::Get()
{
	check(GEngine);

	UAssetManager_MiniJam155* MyAssetManger = Cast<UAssetManager_MiniJam155>(GEngine->AssetManager);
	return *MyAssetManger;
}

void UAssetManager_MiniJam155::StartInitialLoading()
{
	Super::StartInitialLoading();

	FGameplayTags::InitializeNativeTags();
}
