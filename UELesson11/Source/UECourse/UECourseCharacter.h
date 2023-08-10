// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Delegates/Delegate.h"
#include "UECourseCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCollected, int, HitPoints);

UCLASS(config=Game)
class AUECourseCharacter : public ACharacter//, public IFighterInterface
{
	GENERATED_BODY()

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AUECourseCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float RightInputValue;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float ForwardInputValue;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float TurnInputRate;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite)
	bool IsStunned = false;
	
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite)
	bool IsAttacking = false;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ItemClass;
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(Server, Reliable)
	void Stun_Server();

	UFUNCTION(Server, Reliable)
	void Attack_Server();

	UFUNCTION(NetMulticast, Reliable)
	void Attack_NetMulticast();
	
	UFUNCTION(Server, Reliable)
	void MoveForward_Server(float Value);

	UFUNCTION(Client, Reliable)
	void MoveForward_Client(float Value);

	UFUNCTION(Server, Reliable)
	void MoveRight_Server(float Value);
	
	UFUNCTION(Client, Reliable)
	void MoveRight_Client(float Value);
	
	UFUNCTION(Server, Reliable)
	void Turn_Server(float Rate);
	
	UFUNCTION(Client, Reliable)
	void Turn_Client(float Rate);

	void LookUp(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable, Category = Character)
	virtual void ShowInfo();

	UFUNCTION(BlueprintCallable, Category = Character)
	void InvokeDamage(int Damage);

	UFUNCTION(BlueprintCallable, Category = Character)
	int DealDamage();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnItemCollected OnItemCollected;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MaxHP = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int CurrentHP = 100;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCharacterWidget> PlayerHUDClass;

	UPROPERTY(EditAnywhere)
	class UCharacterWidget* PlayerHUD;

private:
	void Log(FString Name, FString ClassName);
};