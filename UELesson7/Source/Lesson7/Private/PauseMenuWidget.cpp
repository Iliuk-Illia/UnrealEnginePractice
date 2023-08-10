// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenuWidget.h"

#include "Kismet/GameplayStatics.h"
#include "Lesson7/Lesson7Character.h"

void UPauseMenuWidget::OnResume()
{
	//ResumeDelegate.Broadcast();
	ResumeDelegate2.Execute();
}

void UPauseMenuWidget::OnExitGame()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	PlayerController->ConsoleCommand(TEXT("exit"));
}

void UPauseMenuWidget::OnNextTab()
{
	WidgetSwitcher->SetActiveWidgetIndex(1);
}

void UPauseMenuWidget::OnPrewTab()
{
	WidgetSwitcher->SetActiveWidgetIndex(0);
}

void UPauseMenuWidget::CheckVisibility(bool Check)
{
	ALesson7Character* Player = Cast<ALesson7Character>(GetWorld()->GetFirstPlayerController()->GetPawn());
	Player->IsDisplayName = Check;
	Player->NameWidget->SetVisibility(Check);
}


void UPauseMenuWidget::NativeConstruct()
{
	if (ResumeButton != nullptr)
	{
		ResumeButton->OnClicked.AddDynamic(this,&UPauseMenuWidget::OnResume);
	}
	if (ExitGameButton != nullptr)
	{
		ExitGameButton->OnClicked.AddDynamic(this,&UPauseMenuWidget::OnExitGame);
	}
	if (PrewTabButton != nullptr)
	{
		PrewTabButton->OnClicked.AddDynamic(this,&UPauseMenuWidget::OnPrewTab);
	}
	if (NextTabButton != nullptr)
	{
		NextTabButton->OnClicked.AddDynamic(this,&UPauseMenuWidget::OnNextTab);
	}
	if (NameVisibility != nullptr)
	{
		NameVisibility->OnCheckStateChanged.AddDynamic(this,&UPauseMenuWidget::CheckVisibility);
	}
}
