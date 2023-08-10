// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewActor.generated.h"

UCLASS()
class UECOURSE_API ANewActor : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ANewActor();

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh; 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int OtherBodyIndex,
						bool BFromSweep,
						const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int OtherBodyIndex);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent,
			   AActor* OtherActor,
			   UPrimitiveComponent* OtherComp,
			   FVector NormalImpulse,
			   const FHitResult& Hit);
	
	void PrintMessage(FColor Color, FString Message, int Key);
};
