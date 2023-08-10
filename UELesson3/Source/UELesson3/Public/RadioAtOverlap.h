// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RadioBase.h"
#include "Components/BoxComponent.h"
#include "RadioAtOverlap.generated.h"

/**
 * 
 */
UCLASS()
class UELESSON3_API ARadioAtOverlap : public ARadioBase
{
	GENERATED_BODY()
	
public:
	ARadioAtOverlap();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UBoxComponent* Box;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int OtherBodyIndex,
						bool FromSweep,
						const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int OtherBodyIndex);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
