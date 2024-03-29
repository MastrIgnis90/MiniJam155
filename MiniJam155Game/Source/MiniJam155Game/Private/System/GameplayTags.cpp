// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTags.h"
#include "GameplayTagsManager.h"

FGameplayTags FGameplayTags::GameplayTags;

void FGameplayTags::InitializeNativeTags()
{
	UGameplayTagsManager& GameplayTagsManager = UGameplayTagsManager::Get();

	GameplayTags.AddAllTags(GameplayTagsManager);

	GameplayTagsManager.DoneAddingNativeTags();
}

void FGameplayTags::AddAllTags(UGameplayTagsManager& Manager)
{
	AddTag(InputTag_Move, "InputTag.Move", "Move Input.");
	AddTag(InputTag_Jump, "InputTag.Jump", "Jump input.");
}

void FGameplayTags::AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment)
{
	OutTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TEXT("(Native" )) + FString(TagComment));
}
