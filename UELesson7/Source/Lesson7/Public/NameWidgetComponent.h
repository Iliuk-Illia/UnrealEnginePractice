// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "NameWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class LESSON7_API UNameWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetName(FName name);

};
