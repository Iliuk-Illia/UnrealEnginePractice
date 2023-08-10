// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OnInteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UOnInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UELESSON6_API IOnInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteract();
};
