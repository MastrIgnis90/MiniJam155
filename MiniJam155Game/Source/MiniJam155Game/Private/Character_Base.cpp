// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Base.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputComponent_Default.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "System/GameplayTags.h"


// Sets default values
ACharacter_Base::ACharacter_Base()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FollowCamera->SetupAttachment(GetCapsuleComponent());
	FollowCamera->SetRelativeLocation(FVector(-40.f, 1.75f, 64.f));
	FollowCamera->bUsePawnControlRotation = false;

	BoxMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharacterBox"));
	BoxMeshComponent->SetupAttachment(RootComponent);

	Cursor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cursor"));
	Cursor->SetupAttachment(RootComponent);
	
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
	EnhancedInputComponent->BindActionByTag(InputConfig, GameplayTags.InputTag_Aim, ETriggerEvent::Triggered, this, &ACharacter_Base::Input_Aim);
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


void ACharacter_Base::Input_Aim(const FInputActionValue& InputActionValue)
{
	/*
	if(IsValid(Controller))
	{
		const FVector2D AimValue = InputActionValue.Get<FVector2D>();
		FHitResult HitResult;

		if(Cast<APlayerController>(Controller)->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, HitResult))
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *HitResult.Location.ToString())
			const FRotator Rotator = FRotator(GetActorRotation().Roll, UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), HitResult.Location).Pitch, GetActorRotation().Yaw);
			BoxMeshComponent->SetWorldRotation(Rotator);
		}
	}
	*/

	if(IsValid(Controller))
	{
		FHitResult HitResult;
		if(Cast<APlayerController>(Controller)->GetHitResultUnderCursorByChannel(TraceTypeQuery1, true, HitResult))
		{
			Cursor->SetWorldLocation(HitResult.Location);
		}
	}
}


void ACharacter_Base::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * GetWorld()->GetDeltaSeconds());
}

void ACharacter_Base::LookAtRate(float Rate)
{
	AddControllerPitchInput(Rate * GetWorld()->GetDeltaSeconds());
}

