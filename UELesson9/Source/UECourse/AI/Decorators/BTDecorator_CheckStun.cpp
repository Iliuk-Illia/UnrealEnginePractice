// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CheckStun.h"

#include "UECourse/AI/AICharacter.h"
#include "UECourse/AI/CourseAIController.h"

bool UBTDecorator_CheckStun::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if(ACourseAIController* Controller = Cast<ACourseAIController>(OwnerComp.GetOwner()))
	{
		if(AAICharacter* Character = Cast<AAICharacter>(Controller->GetPawn()))
		{
			return Character->IsStunned;
		}
	}

	return false;
}
