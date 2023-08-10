// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadioBase.h"
#include "RadioOnBeginGame.generated.h"

/**
 * 
 */
UCLASS()
class UELESSON3_API ARadioOnBeginGame : public ARadioBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARadioOnBeginGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
