// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnInteractInterface.h"
#include "Components/PointLightComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include <UELesson6/UELesson6Character.h>
#include "PointLightActor.generated.h"

UCLASS()
class UELESSON6_API APointLightActor : public AActor, public IOnInteractInterface
{
	GENERATED_BODY()
	
public:	
	APointLightActor();

	AUELesson6Character* Listener;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Light;
	
	UPROPERTY(EditAnywhere)
	UCurveLinearColor* CurveColor;

	UPROPERTY(EditAnywhere)
	UTimelineComponent* Timeline;

	UFUNCTION()
	void LightColor(FLinearColor Color);
	
	FLinearColor CurentColor;

	void OnInteract_Implementation() override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
