// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerPawn.h"
#include "MyPlayerPawn.generated.h"

/**
 * 
 */
UCLASS()
class UELESSON4_API AMyPlayerPawn : public APlayerPawn
{
	GENERATED_BODY()
public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void Spawn();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> ItemClass;

	TArray<AActor*> InstantiatedActors;

	void MovePitch(float Value);
	
	void MeshScaleUp();

	void MeshScaleDown();
	
	FVector MaxScale = {2.f,2.f,2.f};
	
	FVector MinScale = {0.5f,0.5f,0.5f};

	float ScaleRate = 0.25f;
};
