// Fill out your copyright notice in the Description page of Project Settings.


#include "ScalableActor.h"

AScalableActor::AScalableActor()
{
	PrimaryActorTick.bCanEverTick = true;
	StaticMash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMash"));
	StaticMash->SetupAttachment(RootComponent);
}

void AScalableActor::OnInteract_Implementation() 
{
	FVector NewScale = FVector(FMath::RandRange(1, 4), FMath::RandRange(1, 4), FMath::RandRange(1, 4));
	StaticMash->SetRelativeScale3D(NewScale);
}

void AScalableActor::DestroyCube() 
{
	Destroy();
}

void AScalableActor::BeginPlay()
{
	Super::BeginPlay();

	Listener = Cast<AUELesson6Character>(GetWorld()->GetFirstPlayerController()->GetPawn());

	Listener->OnEKeyPressedDelegate.AddUObject(this, &AScalableActor::OnInteract_Implementation);
	Listener->OnFKeyPressedDelegate.AddUObject(this, &AScalableActor::DestroyCube);
}

void AScalableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

