// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CourseAIController.generated.h"

UCLASS()
class UECOURSE_API ACourseAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PatrolRadius;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName LocationKey;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName DetectedEnemyKey;
};
