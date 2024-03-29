// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

class UGameplayTagsManager;
/**
 * 
 */
struct FGameplayTags
{
public:
	static const FGameplayTags& Get() { return GameplayTags; }

	static void InitializeNativeTags();

	FGameplayTag InputTag_Move;
	FGameplayTag InputTag_Aim;

protected:
	void AddAllTags(UGameplayTagsManager& Manager);

	void AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment);

private:
	static FGameplayTags GameplayTags;
};
