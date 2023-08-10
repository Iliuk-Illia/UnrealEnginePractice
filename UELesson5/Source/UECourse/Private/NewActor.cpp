// Fill out your copyright notice in the Description page of Project Settings.


#include "NewActor.h"

// Sets default values
ANewActor::ANewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScene"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMash"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANewActor::BeginPlay()
{
	Super::BeginPlay();
	
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ANewActor::OnBeginOverlap);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ANewActor::OnEndOverlap);
	StaticMesh->OnComponentHit.AddDynamic(this, &ANewActor::OnHit);
}

// Called every frame
void ANewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANewActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool BFromSweep, const FHitResult& SweepResult)
{
	PrintMessage(FColor::Purple, FString::Printf(TEXT("%s begin overlapping with %s"), *OtherActor->GetName(), *this->GetName()), 0);
}

void ANewActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex)
{
	PrintMessage(FColor::Orange, FString::Printf(TEXT("%s end overlapping with %s"), *OtherActor->GetName(), *this->GetName()), 0);
}

void ANewActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	PrintMessage(FColor::Red, FString::Printf(TEXT("%s hit with %s"), *OtherActor->GetName(), *this->GetName()), 2);
}


void ANewActor::PrintMessage(FColor Color, FString Message, int Key)
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(Key, 5.f, Color, Message);
	}
}
