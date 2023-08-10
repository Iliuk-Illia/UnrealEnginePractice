// Copyright Epic Games, Inc. All Rights Reserved.

#include "UECourseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// AUECourseCharacter

AUECourseCharacter::AUECourseCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AUECourseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AUECourseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AUECourseCharacter::Attack);
	PlayerInputComponent->BindAction("Stun", IE_Pressed, this, &AUECourseCharacter::Stun);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AUECourseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AUECourseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AUECourseCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AUECourseCharacter::LookUp);
}

void AUECourseCharacter::Turn(float Rate)
{
	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking)
	{
		TurnInputRate = Rate;
	}
	else
	{
		TurnInputRate = 0.0f;
	}

	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AUECourseCharacter::LookUp(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AUECourseCharacter::MoveForward(float Value)
{
	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking)
	{
		ForwardInputValue = Value;

		if ((Controller != nullptr) && (Value != 0.0f))
		{
			// find out which way is forward
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Value);
		}
	}
	else
	{
		ForwardInputValue = 0.0f;
	}
}

void AUECourseCharacter::MoveRight(float Value)
{
	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Walking)
	{
		RightInputValue = Value;

		if ((Controller != nullptr) && (Value != 0.0f))
		{
			// find out which way is right
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get right vector 
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			// add movement in that direction
			AddMovementInput(Direction, Value);
		}
	}
	else
	{
		RightInputValue = 0.0f;
	}
}

void AUECourseCharacter::Log(FString Name, FString ClassName)
{
	UE_LOG(LogTemp, Warning, TEXT("Found an actor - %s - %s "), *Name, *ClassName);
}

void AUECourseCharacter::Attack()
{
	IsAttacking = true;

	GetCharacterMovement()->DisableMovement();
	
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AUECourseCharacter::EndAttack, 1.f, false);
}

void AUECourseCharacter::Stun()
{
	IsStunned = true;

	GetCharacterMovement()->DisableMovement();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AUECourseCharacter::EndStun, 5.f, false);
}

void AUECourseCharacter::EndStun()
{
	IsStunned = false;

	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}

void AUECourseCharacter::EndAttack()
{
	IsAttacking = false;

	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}


