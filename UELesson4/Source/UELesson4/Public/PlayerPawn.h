// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerPawn.generated.h"

UCLASS()
class UELESSON4_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Camera;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ZoomIn();

	void ZoomOut();

	void MoveForward(float Value);

	void MoveRight(float Value);

	void LookUp(float Value);

	void LookRight(float Value);

	UPROPERTY(EditDefaultsOnly)
	float Speed = 100.f;

	UPROPERTY(EditDefaultsOnly)
	float TurnRate = 50.f;
	
	float ZoomFieldOfViewStep = 2.5f;

	float ZoomLengthStep = 16.166f;
};
