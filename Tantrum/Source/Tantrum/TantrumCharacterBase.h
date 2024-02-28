// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TantrumCharacterBase.generated.h"

class AThrowableActor;

UENUM(BlueprintType)
enum class ECharacterThrowState : uint8
{
	None			UMETA(DisplayName = "None"),
	RequestingPull	UMETA(DisplayName = "RequestingPull"),
	Pulling			UMETA(DisplayName = "Pulling"),
	Attached		UMETA(DisplayName = "Attached"),
	Throwing		UMETA(DisplayName = "Throwing"),
};

UCLASS()
class TANTRUM_API ATantrumCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATantrumCharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Landed(const FHitResult& Hit) override;

	void RequestSprintStart();
	void RequestSprintEnd();

	void RequestThrowObject();
	void RequestPullObject();
	void RequestStopPullObject();
	void ResetThrowableObject();

	void OnThrowableAttached(AThrowableActor* InThowableActor);

	bool CanThrowObject() const { return CharacterThrowState == ECharacterThrowState::Attached; }

	void SphereCastPlayerView();

	void SphereCastActorTransform();

	void LineCastActorTransform();
	
	void ProcessTraceResult(const FHitResult& HitResult);

	bool PlayThrowMontage();

	void UnbindMontage();

	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);

	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	void OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UFUNCTION(BlueprintPure)
	bool IsPullingObject() const { return CharacterThrowState == ECharacterThrowState::RequestingPull || CharacterThrowState == ECharacterThrowState::Pulling; }

	UFUNCTION(BlueprintPure)
	bool IsThrowingObject() const { return CharacterThrowState == ECharacterThrowState::Throwing; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintSpeed = 1200.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
	float MinImpactSpeed = 600.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
	float MaxImpactSpeed = 1200.0f;

	//Time in Seconds
	UPROPERTY(EditAnywhere, Category = "Fall Impact")
	float MinStunTime = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
	float MaxStunTime = 1.0f;

	float StunTime = 0.0f;
	float StunBeginTimestamp = 0.0f;

	bool bIsStunned = false;
	bool bIsSprinting = false;

	float MaxWalkSpeed = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Throw")
	ECharacterThrowState CharacterThrowState = ECharacterThrowState::None;

	UPROPERTY(EditAnywhere, Category = "Throw", meta = (ClampMin = "0.0", Unit = "ms"))
	float ThrowSpeed = 2000.0f;

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* ThrowMontage = nullptr;

	FOnMontageBlendingOutStarted BlendingOutDelegate;
	FOnMontageEnded MontageEndedDelegate;

	void OnStunBegin(float StunRatio);
	void UpdateStun();
	void OnStunEnd();

private:

	UPROPERTY()
	AThrowableActor* ThrowableActor;
};
