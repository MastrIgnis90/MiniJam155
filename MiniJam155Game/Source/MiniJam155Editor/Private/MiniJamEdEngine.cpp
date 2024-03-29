// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniJamEdEngine.h"

#include "ISourceControlModule.h"

void UMiniJamEdEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);

	const ISourceControlModule& SourceControlModule = ISourceControlModule::Get();
	{
		ISourceControlProvider& SourceControlProvider = SourceControlModule.GetProvider();

		const TArray<FString> Branches {"origin/main"};
		SourceControlProvider.RegisterStateBranches(Branches, TEXT("Content"));
	}
}
