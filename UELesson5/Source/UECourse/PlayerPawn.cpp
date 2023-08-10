// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	CapsuleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	CapsuleComponent->SetCapsuleHalfHeight(90.f);
	CapsuleComponent->SetCapsuleRadius(50.f);
	RootComponent = CapsuleComponent;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(StaticMeshComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
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

// bBlockingHit – показує, чи сталося зіткнення, тобто Block. При Overlap та Ignore false.
// bStartPenetrating – показує, чи сталося зіткнення на самому початку лінії, тобто коли дистанція є нульовою. Часто вказує на те, що початок лінії знаходиться всередині об’єкта і щоб вирішити це, потрібно добавити цей об’єкт в масив IgnoredActors.
// Time – частина пройденого шляху лінії до першої блокуючої колізії. Є в межах від 0 до 1. Наприклад, якщо довжина лінії (вираховується зі Start та End) 200, а блокуюча колізія сталася на 50, то Time дорівнює 0,25.
// Distance – довжина лінії трасування. Вираховується зі Start та End.
// Location – локація зіткнення. При трасуванні фігур, середина цієї фігури при колізії.
// ImpactPoint – при лінійному трасуванні те ж саме, що і Location. При трасуванні фігур, точна локація зіткнення, наприклад точка на поверхні сфери.
// Normal – нормалізований перпендикулярний вектор відбиття від поверхні, на якій відбулася колізія.
// Impact Normal – в більшості випадків те саме, що і Normal.
// Actor – актор, з яким відбулося зіткнення.
// Component – компонент актора, з яким безпосередньо відбулося зіткнення.

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ZoomIn"), EInputEvent::IE_Pressed, this, &APlayerPawn::ZoomIn);
	PlayerInputComponent->BindAction(TEXT("ZoomOut"), EInputEvent::IE_Pressed, this, &APlayerPawn::ZoomOut);
	
	PlayerInputComponent->BindAction(TEXT("TraceMulti"), EInputEvent::IE_Pressed, this, &APlayerPawn::NewTraceMulti);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APlayerPawn::LookRight);
}

void APlayerPawn::ZoomIn()
{
	float ZoomFieldOfViewStep = 2.5f;
	float ZoomLengthStep = 16.166f;

	CameraComponent->FieldOfView = FMath::Clamp(CameraComponent->FieldOfView - ZoomFieldOfViewStep, 75.0f, 90.0f);
	SpringArmComponent->TargetArmLength = FMath::Clamp(SpringArmComponent->TargetArmLength - ZoomLengthStep, 200.0f, 300.0f);
}

void APlayerPawn::ZoomOut()
{
	float ZoomFieldOfViewStep = 2.5f;
	float ZoomLengthStep = 16.166f;

	CameraComponent->FieldOfView = FMath::Clamp(CameraComponent->FieldOfView + ZoomFieldOfViewStep, 75.0f, 90.0f);
	SpringArmComponent->TargetArmLength = FMath::Clamp(SpringArmComponent->TargetArmLength + ZoomLengthStep, 200.0f, 300.0f);
}

void APlayerPawn::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		float DirectionLength = 100.0f;
		FVector ForwardDirection = GetActorForwardVector() * DirectionLength;
		
		AddActorWorldOffset(ForwardDirection * Value * GetWorld()->GetDeltaSeconds(), true);
	}
}

void APlayerPawn::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		float DirectionLength = 100.0f;
		FVector RightDirection = GetActorRightVector() * DirectionLength;

		AddActorWorldOffset(RightDirection * Value * GetWorld()->GetDeltaSeconds(), true);
	}
}

void APlayerPawn::LookUp(float Value)
{
	if (Value != 0.0f)
	{
		float TurnRate = 50.0f;
		AddControllerPitchInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerPawn::LookRight(float Value)
{
	if (Value != 0.0f)
	{
		float TurnRate = 50.0f;
		AddControllerYawInput(Value * TurnRate * GetWorld()->GetDeltaSeconds());
	}
}


void APlayerPawn::NewTraceMulti()
{
	TArray<FHitResult> Hits;

	UKismetSystemLibrary::LineTraceMulti(this,
												   GetActorLocation(),
												   GetActorLocation() + GetActorForwardVector() * 500.f,
												   UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility),
												   false,
												   { },
												   EDrawDebugTrace::ForDuration,
												   Hits,
												   true);
	
	for(FHitResult& Hit : Hits)
	{
		if(Hit.bBlockingHit)
		{
			PrintMessage(FColor::Purple, FString::Printf(TEXT("Line Trace Hit with %s"), *Hit.Actor.Get()->GetName()),2);
			PrintMessage(FColor::Purple, FString::Printf(TEXT("Distance - %f"), Hit.Distance),1);
			PrintMessage(FColor::Purple, FString(Hit.Location.ToString()),0);
		}
		if(!Hit.bBlockingHit)
		{
			PrintMessage(FColor::Emerald, FString::Printf(TEXT("Line Trace Overlap with %s"), *Hit.Actor.Get()->GetName()),7);
			PrintMessage(FColor::Emerald, FString::Printf(TEXT("Distance - %f"), Hit.Distance),6);
			PrintMessage(FColor::Emerald, FString(Hit.Location.ToString()),5);

		}
	}
}

void APlayerPawn::PrintMessage(FColor Color, FString Message, int Key)
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(Key, 5.f, Color, Message);
	}
}