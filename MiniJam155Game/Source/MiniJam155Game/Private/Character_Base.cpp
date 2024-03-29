// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Base.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputComponent_Default.h"
#include "GameplayTags.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ACharacter_Base::ACharacter_Base()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FollowCamera->SetupAttachment(GetCapsuleComponent());
	FollowCamera->SetRelativeLocation(FVector(-40.f, 1.75f, 64.f));
	FollowCamera->bUsePawnControlRotation = true;

	
}

// Called when the game starts or when spawned
void ACharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ACharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent_Default* EnhancedInputComponent = Cast<UEnhancedInputComponent_Default>(PlayerInputComponent);

	check(EnhancedInputComponent);

	const FGameplayTags& GameplayTags = FGameplayTags::Get();

	EnhancedInputComponent->BindActionByTag(InputConfig, GameplayTags.InputTag_Move, ETriggerEvent::Triggered, this, &ACharacter_Base::Input_Move);
}

void ACharacter_Base::Input_Move(const FInputActionValue& InputActionValue)
{
	if(IsValid(Controller))
	{
		const FVector2D MoveValue = InputActionValue.Get<FVector2D>();
		const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.0f);

		if(MoveValue.X != 0.0f)
		{
			const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
			AddMovementInput(MovementDirection, MoveValue.X);
		}

		if(MoveValue.Y != 0.0f)
		{
			const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
			AddMovementInput(MovementDirection, MoveValue.Y);
		}
	}
}

