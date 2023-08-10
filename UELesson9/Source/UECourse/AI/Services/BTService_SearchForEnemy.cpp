// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SearchForEnemy.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UECourse/UECourseCharacter.h"
#include "UECourse/AI/AICharacter.h"
#include "UECourse/AI/CourseAIController.h"

UBTService_SearchForEnemy::UBTService_SearchForEnemy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Search For Enemy";
	
	EnemyKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_SearchForEnemy, EnemyKey), AActor::StaticClass());
}

void UBTService_SearchForEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ACourseAIController* Controller = Cast<ACourseAIController>(OwnerComp.GetOwner());

	if(Controller == nullptr)
	{
		return;
	}

	AAICharacter* Character = Cast<AAICharacter>(Controller->GetPawn());

	if(Character == nullptr)
	{
		return;
	}

	float Radius = Controller->PatrolRadius;
	FVector Location = Character->GetActorLocation();

	TArray<FHitResult> OutHits;

	UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(),
												     Location,
												     Location,
												     Radius,
												     { UEngineTypes::ConvertToObjectType(ECC_Pawn) },
												     false,
												     {},
												     EDrawDebugTrace::ForOneFrame,
												     OutHits,
												     true);
	
	Controller->GetBlackboardComponent()->SetValueAsObject(EnemyKey.SelectedKeyName, nullptr);
	
	for(FHitResult& HitResult : OutHits)
	{
		if(HitResult.Actor != nullptr)
		{
			if(AUECourseCharacter* Enemy = Cast<AUECourseCharacter>(HitResult.Actor))
			{
				Controller->GetBlackboardComponent()->SetValueAsObject(EnemyKey.SelectedKeyName, Enemy);
			}
		}
	}
}

