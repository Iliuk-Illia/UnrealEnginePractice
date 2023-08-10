// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsAlive.h"

#include "UECourse/AI/AICharacter.h"
#include "UECourse/AI/CourseAIController.h"

bool UBTDecorator_IsAlive::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if(ACourseAIController* Controller = Cast<ACourseAIController>(OwnerComp.GetOwner()))
	{
		if(AAICharacter* Character = Cast<AAICharacter>(Controller->GetPawn()))
		{
			if(Character->CurrentHP <= 0)
			{
				Character->IsStunned = true;
				return false;
			}
		}
	}

	return true;
}
