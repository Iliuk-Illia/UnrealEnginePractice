// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SetSpeed.h"

#include "UECourse/AI/AICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UECourse/AI/CourseAIController.h"

void UBTService_SetSpeed::OnSearchStart(FBehaviorTreeSearchData& SearchData)
{
	if(ACourseAIController* Controller = Cast<ACourseAIController>(SearchData.OwnerComp.GetOwner()))
	{
		if(AAICharacter* Character = Cast<AAICharacter>(Controller->GetPawn()))
		{
			Character->GetCharacterMovement()->MaxWalkSpeed = Speed;
		}
	}
}
