// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "ThirdPersonNameWidget.generated.h"

/**
 * 
 */
UCLASS()
class LESSON7_API UThirdPersonNameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta=(BindWidget), BlueprintReadWrite)
	UTextBlock* NameLable;
	
	UFUNCTION(BlueprintCallable)
	void SetCharacterName(FName name);

};
