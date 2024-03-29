// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Editor/UnrealEdEngine.h"
#include "MiniJamEdEngine.generated.h"

/**
 * 
 */
UCLASS()
class MINIJAM155EDITOR_API UMiniJamEdEngine : public UUnrealEdEngine
{
	GENERATED_BODY()

public:
	virtual void Init(IEngineLoop* InEngineLoop) override;
};
