// Fill out your copyright notice in the Description page of Project Settings.


#include "UELesson3/Public/RadioAtOverlap.h"

#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"

ARadioAtOverlap::ARadioAtOverlap()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("RadioAtOverlapBox"));
	Box -> SetupAttachment(Scene);
	
	Box->SetBoxExtent(FVector(200.f, 200.f, 100.f));
	Box->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void ARadioAtOverlap::BeginPlay()
{
	Super::BeginPlay();
	PauseRadio(true);

	Box->OnComponentBeginOverlap.AddDynamic(this, &ARadioAtOverlap::OnOverlapBegin);
	Box->OnComponentEndOverlap.AddDynamic(this, &ARadioAtOverlap::OnOverlapEnd);
}


void ARadioAtOverlap::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	if(OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		PauseRadio(false);
	}
}
void ARadioAtOverlap::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex)
{
	if(OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		PauseRadio(true);
	}
}
