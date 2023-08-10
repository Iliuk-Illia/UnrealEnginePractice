// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerPawn.h"


void AMyPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAction(TEXT("MeshScaleUp"), IE_Pressed, this, &AMyPlayerPawn::MeshScaleUp);
	PlayerInputComponent->BindAction(TEXT("MeshScaleDown"), IE_Pressed, this, &AMyPlayerPawn::MeshScaleDown);
	PlayerInputComponent->BindAction(TEXT("Spawn"), IE_Pressed, this, &AMyPlayerPawn::Spawn);

	PlayerInputComponent->BindAxis(TEXT("MovePitch"), this, &AMyPlayerPawn::MovePitch);
}

void AMyPlayerPawn::MeshScaleUp()
{
	SetActorScale3D(ClampVector(GetActorScale() + ScaleRate, MinScale, MaxScale));
}
void AMyPlayerPawn::MeshScaleDown()
{
	SetActorScale3D(ClampVector(GetActorScale() - ScaleRate, MinScale, MaxScale));
}

void AMyPlayerPawn::Spawn()
{
	if(ItemClass != NULL)
	{
		FVector SpawnLocation = GetActorLocation() + 100 * GetActorForwardVector();
		FRotator SpawnRotator = GetActorRotation();
		FActorSpawnParameters SpawnParameters;

		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ItemClass, SpawnLocation, SpawnRotator, SpawnParameters);
		InstantiatedActors.Add(SpawnedActor);
	}
}

void AMyPlayerPawn::MovePitch(float Value)
{
	for (auto& actor : InstantiatedActors)
	{
		if (IsValid(actor)) {
			actor->AddActorLocalRotation(FRotator(5, 0, 0) * GetWorld()->GetDeltaSeconds());
		}
	}
}

