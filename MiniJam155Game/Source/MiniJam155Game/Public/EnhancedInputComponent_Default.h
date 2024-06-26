// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "System/InputConfig.h"
#include "EnhancedInputComponent_Default.generated.h"

struct FGameplayTag;
/**
 * 
 */
UCLASS()
class MINIJAM155GAME_API UEnhancedInputComponent_Default : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserClass, typename FuncType>
	void BindActionByTag(const UInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func);
};

template <class UserClass, typename FuncType>
void UEnhancedInputComponent_Default::BindActionByTag(const UInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func)
{
	check(InputConfig)
	if(const UInputAction* IA = InputConfig->FindInputActionForTag(InputTag))
	{
		BindAction(IA, TriggerEvent, Object, Func);
	}
}

