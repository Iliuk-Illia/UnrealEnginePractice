// Fill out your copyright notice in the Description page of Project Settings.

#include "UELesson3/Public/RadioBase.h"

#include "EditorTutorial.h"
#include "Components/AudioComponent.h"

// Sets default values
ARadioBase::ARadioBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("RadioScene"));
	Scene -> SetupAttachment(RootComponent);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RadioStaticMesh"));
	StaticMesh -> SetupAttachment(Scene);
	
	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("RadioAudio"));
	Audio -> SetupAttachment(Scene);
}

// Called when the game starts or when spawned
void ARadioBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARadioBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ARadioBase::PauseRadio_Implementation(bool pause)
{
	Audio->SetPaused(pause);
}

