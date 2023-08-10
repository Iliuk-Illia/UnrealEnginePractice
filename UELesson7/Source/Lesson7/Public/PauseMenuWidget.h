// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/EditableTextBox.h"
#include "Components/WidgetSwitcher.h"
#include "PauseMenuWidget.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FMultiDelegate)
DECLARE_DELEGATE(UDelegate)


UCLASS()
class LESSON7_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//UPROPERTY()
	//FMultiDelegate ResumeDelegate;
	
	UFUNCTION()
	UDelegate ResumeDelegate2;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UWidgetSwitcher* WidgetSwitcher;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* ResumeButton;

	UFUNCTION(BlueprintCallable)
	void OnResume();
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* ExitGameButton;

	UFUNCTION(BlueprintCallable)
	void OnExitGame();

	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* PrewTabButton;

	UFUNCTION(BlueprintCallable)
	void OnPrewTab();

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* NextTabButton;
	
	UFUNCTION(BlueprintCallable)
	void OnNextTab();

	
	UPROPERTY(EditAnywhere, meta=(BindWidget), BlueprintReadOnly)
	UEditableTextBox* NewName;
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UCheckBox* NameVisibility;

	UFUNCTION(BlueprintCallable)
	void CheckVisibility(bool Check);
	
	virtual void NativeConstruct() override;
};
