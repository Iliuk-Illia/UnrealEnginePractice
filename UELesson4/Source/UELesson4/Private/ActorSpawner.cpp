// Fill out your copyright notice in the Description page of Project Settings.


#include "UELesson4/Public/ActorSpawner.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AActorSpawner::AActorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxCollision->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AActorSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorSpawner::Spawn()
{
	if(ItemClass != NULL)
	{
		FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(BoxCollision->GetComponentLocation(),
																				   BoxCollision->GetScaledBoxExtent());
		FRotator SpawnRotator = FRotator();
		FActorSpawnParameters SpawnParameters;

		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ItemClass, SpawnLocation, SpawnRotator, SpawnParameters);
	}
}

