// Fill out your copyright notice in the Description page of Project Settings.


#include "UELesson4/Public/PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScene"));
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	StaticMesh->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ZoomIn"), IE_Pressed, this, &APlayerPawn::ZoomIn);
	PlayerInputComponent->BindAction(TEXT("ZoomOut"), IE_Pressed, this, &APlayerPawn::ZoomOut);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APlayerPawn::LookRight);
}

void APlayerPawn::MoveForward(float Value)
{
	if(Value != 0.f)
	{
		FVector ForwardDirection = GetActorForwardVector() * Speed;

		SetActorLocation(GetActorLocation() + ForwardDirection * Value * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerPawn::MoveRight(float Value)
{
	if(Value != 0.f)
	{
		FVector RightDirection = GetActorRightVector() * Speed;

		SetActorLocation(GetActorLocation() + RightDirection * Value * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerPawn::LookUp(float Value)
{
	if(Value != 0.f)
	{
		AddControllerPitchInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerPawn::LookRight(float Value)
{
	if(Value != 0.f)
	{
		AddControllerYawInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerPawn::ZoomIn()
{
	Camera->FieldOfView = FMath::Clamp(Camera->FieldOfView - ZoomFieldOfViewStep, 75.f, 90.f);
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength - ZoomLengthStep, 200.f, 300.f);
}

void APlayerPawn::ZoomOut()
{
	Camera->FieldOfView = FMath::Clamp(Camera->FieldOfView + ZoomFieldOfViewStep, 75.f, 90.f);
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength + ZoomLengthStep, 200.f, 300.f);
}



