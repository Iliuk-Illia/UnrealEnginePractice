// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"

#include "UECourse/AI/AICharacter.h"
#include "UECourse/AI/CourseAIController.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(ACourseAIController* Controller = Cast<ACourseAIController>(OwnerComp.GetOwner()))
	{
		if(AAICharacter* Character = Cast<AAICharacter>(Controller->GetPawn()))
		{
			Character->Attack();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
