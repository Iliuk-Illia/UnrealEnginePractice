// Fill out your copyright notice in the Description page of Project Settings.

#include "NameWidgetComponent.h"
#include "ThirdPersonNameWidget.h"

void UNameWidgetComponent::SetName(FName name)
{
	UThirdPersonNameWidget* SetNameWidget = Cast<UThirdPersonNameWidget>(GetWidget());

	if (SetNameWidget != nullptr)
	{
		SetNameWidget->SetCharacterName(name);
	}
}