// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetRandomPoint.h"

#include "NavigationSystem.h"
#include "UECourse/AI/AICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UECourse/AI/CourseAIController.h"

UBTTask_GetRandomPoint::UBTTask_GetRandomPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Get Random Point";
	
	Location.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_GetRandomPoint, Location), AActor::StaticClass());
	Location.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_GetRandomPoint, Location));
}

EBTNodeResult::Type UBTTask_GetRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACourseAIController* Controller = Cast<ACourseAIController>(OwnerComp.GetOwner());

	if(Controller == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	float PatrolRadius = Controller->PatrolRadius;

	if(PatrolRadius > 0.f)
	{
		FNavLocation ResultLocation;

		if(UNavigationSystemV1::GetNavigationSystem(&OwnerComp)->GetRandomReachablePointInRadius(Controller->GetNavAgentLocation(),
																							  PatrolRadius,
																							  ResultLocation))
		{
			AAICharacter* Character = Cast<AAICharacter>(Controller->GetPawn());

			if(Character != nullptr)
			{
				Controller->GetBlackboardComponent()->SetValueAsVector(Controller->LocationKey, ResultLocation.Location);

				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
