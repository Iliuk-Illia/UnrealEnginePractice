// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnInteractInterface.h"
#include "GameFramework/Actor.h"
#include <UELesson6/UELesson6Character.h>
#include "ScalableActor.generated.h"

UCLASS()
class UELESSON6_API AScalableActor : public AActor, public IOnInteractInterface
{
	GENERATED_BODY()
	
public:	
	AScalableActor();

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMash;

	AUELesson6Character* Listener;

	void OnInteract_Implementation() override;

	void DestroyCube();
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
