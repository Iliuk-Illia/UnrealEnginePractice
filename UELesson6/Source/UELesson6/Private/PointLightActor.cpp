// Fill out your copyright notice in the Description page of Project Settings.


#include "PointLightActor.h"

#include "Components/LightComponent.h"

// Sets default values
APointLightActor::APointLightActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Timeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));

}

void APointLightActor::BeginPlay()
{
	Super::BeginPlay();

	Listener = Cast<AUELesson6Character>(GetWorld()->GetFirstPlayerController()->GetPawn());
	Listener->OnEKeyPressedDelegate.AddUObject(this, &APointLightActor::OnInteract_Implementation);

	FOnTimelineLinearColor Color;
	
	Color.BindUFunction(this, FName("LightColor"));

	if (CurveColor)
	{
		Timeline->AddInterpLinearColor(CurveColor, Color);
	}

	Timeline->SetLooping(true);
	Timeline->PlayFromStart();
}

void APointLightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APointLightActor::OnInteract_Implementation()
{
	Light->SetLightColor(CurentColor);
}

void APointLightActor::LightColor(FLinearColor Color)
{
	CurentColor = Color;
}