// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonNameWidget.h"

void UThirdPersonNameWidget::SetCharacterName(FName name)
{
	NameLable->SetText(FText::FromName(name));
}