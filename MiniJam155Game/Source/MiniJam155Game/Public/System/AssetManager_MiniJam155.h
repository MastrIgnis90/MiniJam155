// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AssetManager_MiniJam155.generated.h"

/**
 * 
 */
UCLASS()
class MINIJAM155GAME_API UAssetManager_MiniJam155 : public UAssetManager
{
	GENERATED_BODY()

public:

	UAssetManager_MiniJam155();

	static UAssetManager_MiniJam155& Get();

protected:

	virtual void StartInitialLoading() override;
};
