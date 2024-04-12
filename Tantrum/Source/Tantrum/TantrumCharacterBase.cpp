// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumCharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TantrumPlayerController.h"
#include "ThrowableActor.h"
#include "Net/UnrealNetwork.h"
#include "DrawDebugHelpers.h"
#include "TantrumGameInstance.h"
#include "TantrumPlayerState.h"

constexpr int CVSphereCastPlayerView = 0;
constexpr int CVSphereCastActorTransform = 1;
constexpr int CVLineCastActorTransform = 2;


//add cvars for debug
static TAutoConsoleVariable<int> CVarTraceMode(
	TEXT("Tantrum.Character.Debug.TraceMode"),
	0,
	TEXT("    0: Sphere cast PlayerView is used for direction/rotation (default).\n")
	TEXT("    1: Sphere cast using ActorTransform \n")
	TEXT("    2: Line cast using ActorTransform \n"),
	ECVF_Default);


static TAutoConsoleVariable<bool> CVarDisplayTrace(
	TEXT("Tantrum.Character.Debug.DisplayTrace"),
	false,
	TEXT("Display Trace"),
	ECVF_Default);

static TAutoConsoleVariable<bool> CVarDisplayThrowVelocity(
	TEXT("Tantrum.Character.Debug.DisplayThrowVelocity"),
	false,
	TEXT("Display Throw Velocity"),
	ECVF_Default);

// Sets default values
ATantrumCharacterBase::ATantrumCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetReplicateMovement(true);
}

void ATantrumCharacterBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams SharedParams;
	SharedParams.bIsPushBased = true;
	SharedParams.Condition = COND_SkipOwner;

	DOREPLIFETIME_WITH_PARAMS_FAST(ATantrumCharacterBase, CharacterThrowState, SharedParams);

	SharedParams.Condition = COND_None;
	DOREPLIFETIME_WITH_PARAMS_FAST(ATantrumCharacterBase, bIsBeingRescued, SharedParams);
	DOREPLIFETIME_WITH_PARAMS_FAST(ATantrumCharacterBase, LastGroundPosition, SharedParams);


	//DOREPLIFETIME(ATantrumCharacterBase, CharacterThrowState);
}

// Called when the game starts or when spawned
void ATantrumCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	EffectCooldown = DefautlEffectCooldown;
	if (GetCharacterMovement())
	{
		MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	}
}

// Called every frame
void ATantrumCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//this is done on the clients to ensure the anim looks correct
	//no need to spam network traffic with curve value
	if (CharacterThrowState == ECharacterThrowState::Throwing)
	{
		UpdateThrowMontagePlayRate();
		return;
	}

	if (IsBeingRescued())
	{
		UpdateRescue(DeltaTime);
		return;
	}

	if (!IsLocallyControlled())
	{
		return;
	}

	//these should run on the authority to prevent cheating
	if (bIsStunned)
	{
		UpdateStun(DeltaTime);
		return;
	}

	if (bIsUnderEffect)
	{
		UpdateEffect(DeltaTime);
		return;
	}
	//~move to authority, and place the start as a server rpc

	//move to a function and improve this in the future
	//only locallly controlled character needs to worry about below code
	if (CharacterThrowState == ECharacterThrowState::None || CharacterThrowState == ECharacterThrowState::RequestingPull)
	{
		switch (CVarTraceMode->GetInt())
		{
		case CVSphereCastPlayerView:
			SphereCastPlayerView();
			break;
		case CVSphereCastActorTransform:
			SphereCastActorTransform();
			break;
		case CVLineCastActorTransform:
			LineCastActorTransform();
			break;
		default:
			SphereCastPlayerView();
			break;
		}
	}
}

// Called to bind functionality to input
void ATantrumCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATantrumCharacterBase::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	//this should only be authority or maybe locally controlled...

	//custom landed code
	ATantrumPlayerController* TantrumPlayerController = GetController<ATantrumPlayerController>();
	if (TantrumPlayerController)
	{
		const float FallImpactSpeed = FMath::Abs(GetVelocity().Z);
		if (FallImpactSpeed < MinImpactSpeed)
		{
			//nothing to do, very light fall
			return;
		}
		else
		{
			//SoundCue Triggers
			if (HeavyLandSound && GetOwner())
			{
				FVector CharacterLocation = GetOwner()->GetActorLocation();
				UGameplayStatics::PlaySoundAtLocation(this, HeavyLandSound, CharacterLocation);
			}
		}

		const float DeltaImpact = MaxImpactSpeed - MinImpactSpeed;
		const float FallRatio = FMath::Clamp((FallImpactSpeed - MinImpactSpeed) / DeltaImpact, 0.0f, 1.0f);
		const bool bAffectSmall = FallRatio <= 0.5;
		const bool bAffectLarge = FallRatio > 0.5;
		TantrumPlayerController->PlayDynamicForceFeedback(FallRatio, 0.5f, bAffectLarge, bAffectSmall, bAffectLarge, bAffectSmall);

		if (bAffectLarge)
		{
			OnStunBegin(FallRatio);
		}
	}
}

//this might be best to save for authority
void ATantrumCharacterBase::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	if (HasAuthority())
	{
		if (!IsBeingRescued() && (PrevMovementMode == MOVE_Walking && GetCharacterMovement()->MovementMode == MOVE_Falling))
		{
			LastGroundPosition = GetActorLocation() + (GetActorForwardVector() * -100.0f) + (GetActorUpVector() * 100.0f);
		}
	}

	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);
}

void ATantrumCharacterBase::FellOutOfWorld(const class UDamageType& dmgType)
{
	if (HasAuthority())
	{
		StartRescue();
	}
}

void ATantrumCharacterBase::RequestSprintStart()
{
	if (!bIsStunned)
	{
		//handle the local speed as we are still controlling this character and want to avoid any stutter between client and server
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		ServerSprintStart();
	}

}
void ATantrumCharacterBase::RequestSprintEnd()
{
	//handle the local speed as we are still controlling this character and want to avoid any stutter between client and server
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
	ServerSprintEnd();
}


void ATantrumCharacterBase::ServerSprintStart_Implementation()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ATantrumCharacterBase::ServerSprintEnd_Implementation()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
}

void ATantrumCharacterBase::RequestThrowObject()
{
	if (CanThrowObject())
	{
		//to give a responsive feel start playing on the locally owned Actor
		if (PlayThrowMontage())
		{
			CharacterThrowState = ECharacterThrowState::Throwing;
			//now play on all clients
			ServerRequestThrowObject();

		}
		else
		{
			ResetThrowableObject();
		}
	}
}

bool ATantrumCharacterBase::ServerRequestThrowObject_Validate()
{
	//can check the state or if the throwable actor exists etc to prevent this being broadcasted
	return true;
}

void ATantrumCharacterBase::ServerRequestThrowObject_Implementation()
{
	//server needs to call the multicast
	MulticastRequestThrowObject();
}

void ATantrumCharacterBase::MulticastRequestThrowObject_Implementation()
{
	//locally controlled actor has already set up binding and played montage
	if (IsLocallyControlled())
	{
		return;
	}

	PlayThrowMontage();
	CharacterThrowState = ECharacterThrowState::Throwing;
}

void ATantrumCharacterBase::RequestPullObject()
{
	//make sure we are in idle
	if (!bIsStunned && CharacterThrowState == ECharacterThrowState::None)
	{
		CharacterThrowState = ECharacterThrowState::RequestingPull;
		ServerRequestPullObject(true);
	}
}

bool ATantrumCharacterBase::AttemptPullObjectAtLocation(const FVector& InLocation)
{
	if (CharacterThrowState != ECharacterThrowState::None || CharacterThrowState != ECharacterThrowState::RequestingPull)
	{
		return false;
	}

	FVector StartPos = GetActorLocation();
	FVector EndPos = InLocation;
	FHitResult HitResult;
	GetWorld() ? GetWorld()->LineTraceSingleByChannel(HitResult, StartPos, EndPos, ECollisionChannel::ECC_Visibility) : false;
#if ENABLE_DRAW_DEBUG
	if (CVarDisplayTrace->GetBool())
	{
		DrawDebugLine(GetWorld(), StartPos, EndPos, HitResult.bBlockingHit ? FColor::Red : FColor::White, false);
	}
#endif
	CharacterThrowState = ECharacterThrowState::RequestingPull;
	ProcessTraceResult(HitResult, false);
	if (CharacterThrowState == ECharacterThrowState::Pulling)
	{
		return true;
	}

	CharacterThrowState = ECharacterThrowState::None;
	return false;
}

void ATantrumCharacterBase::RequestStopPullObject()
{
	//if was pulling an object, drop it
	if (CharacterThrowState == ECharacterThrowState::RequestingPull)
	{
		CharacterThrowState = ECharacterThrowState::None;
		ServerRequestPullObject(false);
		//ResetThrowableObject();
	}
}

void ATantrumCharacterBase::ServerRequestPullObject_Implementation(bool bIsPulling)
{
	CharacterThrowState = bIsPulling ? ECharacterThrowState::RequestingPull : ECharacterThrowState::None;
}

void ATantrumCharacterBase::ServerPullObject_Implementation(AThrowableActor* InThrowableActor)
{
	if (InThrowableActor && InThrowableActor->Pull(this))
	{
		CharacterThrowState = ECharacterThrowState::Pulling;
		ThrowableActor = InThrowableActor;
		ThrowableActor->ToggleHighlight(false);
	}
}

void ATantrumCharacterBase::ClientThrowableAttached_Implementation(AThrowableActor* InThrowableActor)
{
	CharacterThrowState = ECharacterThrowState::Attached;
	ThrowableActor = InThrowableActor;
	MoveIgnoreActorAdd(ThrowableActor);
}

void ATantrumCharacterBase::ServerBeginThrow_Implementation()
{
	//ignore collisions otherwise the throwable object hits the player capsule and doesn't travel in the desired direction
	if (ThrowableActor->GetRootComponent())
	{
		UPrimitiveComponent* RootPrimitiveComponent = Cast<UPrimitiveComponent>(ThrowableActor->GetRootComponent());
		if (RootPrimitiveComponent)
		{
			RootPrimitiveComponent->IgnoreActorWhenMoving(this, true);
		}
	}
	//const FVector& Direction = GetMesh()->GetSocketRotation(TEXT("ObjectAttach")).Vector() * -ThrowSpeed;
	const FVector& Direction = GetActorForwardVector() * ThrowSpeed;
	ThrowableActor->Launch(Direction);

	if (CVarDisplayThrowVelocity->GetBool())
	{
		const FVector& Start = GetMesh()->GetSocketLocation(TEXT("ObjectAttach"));
		DrawDebugLine(GetWorld(), Start, Start + Direction, FColor::Red, false, 5.0f);
	}
}

void ATantrumCharacterBase::ServerFinishThrow_Implementation()
{
	//put all this in a function that runs on the server
	CharacterThrowState = ECharacterThrowState::None;
	//this only happened on the locally controlled actor
	MoveIgnoreActorRemove(ThrowableActor);
	if (ThrowableActor->GetRootComponent())
	{
		UPrimitiveComponent* RootPrimitiveComponent = Cast<UPrimitiveComponent>(ThrowableActor->GetRootComponent());
		if (RootPrimitiveComponent)
		{
			RootPrimitiveComponent->IgnoreActorWhenMoving(this, false);
		}
	}
	ThrowableActor = nullptr;
}

void ATantrumCharacterBase::ResetThrowableObject()
{
	//drop object
	if (ThrowableActor)
	{
		ThrowableActor->Drop();
	}
	CharacterThrowState = ECharacterThrowState::None;
	ThrowableActor = nullptr;
}

void ATantrumCharacterBase::RequestUseObject()
{
	ApplyEffect_Implementation(ThrowableActor->GetEffectType(), true);
	ThrowableActor->Destroy();
	ResetThrowableObject();
}

void ATantrumCharacterBase::OnThrowableAttached(AThrowableActor* InThrowableActor)
{
	CharacterThrowState = ECharacterThrowState::Attached;
	ThrowableActor = InThrowableActor;
	MoveIgnoreActorAdd(ThrowableActor);
	ClientThrowableAttached(InThrowableActor);
	//InThrowableActor->ToggleHighlight(false);
}

bool ATantrumCharacterBase::IsHovering() const
{
	if (ATantrumPlayerState* TantrumPlayerState = GetPlayerState<ATantrumPlayerState>())
	{
		return TantrumPlayerState->GetCurrentState() != EPlayerGameState::Playing;
	}

	return false;
}

void ATantrumCharacterBase::SphereCastPlayerView()
{
	FVector Location;
	FRotator Rotation;
	if (!GetController())
	{
		return;
	}
	GetController()->GetPlayerViewPoint(Location, Rotation);
	const FVector PlayerViewForward = Rotation.Vector();
	const float AdditionalDistance = (Location - GetActorLocation()).Size();
	FVector EndPos = Location + (PlayerViewForward * (1000.0f + AdditionalDistance));

	const FVector CharacterForward = GetActorForwardVector();
	const float DotResult = FVector::DotProduct(PlayerViewForward, CharacterForward);
	//prevent picking up objects behind us, this is when the camera is looking directly at the characters front side
	if (DotResult < -0.23f)
	{
		if (ThrowableActor)
		{
			ThrowableActor->ToggleHighlight(false);
			ThrowableActor = nullptr;
		}
		return;
		//UE_LOG(LogTemp, Warning, TEXT("Dot Result: %f"), DotResult);
	}


	FHitResult HitResult;
	EDrawDebugTrace::Type DebugTrace = CVarDisplayTrace->GetBool() ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Location, EndPos, 70.0f, UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility), false, ActorsToIgnore, DebugTrace, HitResult, true);
	ProcessTraceResult(HitResult);

#if ENABLE_DRAW_DEBUG
	if (CVarDisplayTrace->GetBool())
	{
		static float FovDeg = 90.0f;
		DrawDebugCamera(GetWorld(), Location, Rotation, FovDeg);
		DrawDebugLine(GetWorld(), Location, EndPos, HitResult.bBlockingHit ? FColor::Red : FColor::White);
		DrawDebugPoint(GetWorld(), EndPos, 70.0f, HitResult.bBlockingHit ? FColor::Red : FColor::White);
	}
#endif

}

void ATantrumCharacterBase::SphereCastActorTransform()
{
	FVector StartPos = GetActorLocation();
	FVector EndPos = StartPos + (GetActorForwardVector() * 1000.0f);

	//sphere trace
	EDrawDebugTrace::Type DebugTrace = CVarDisplayTrace->GetBool() ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None;
	FHitResult HitResult;
	UKismetSystemLibrary::SphereTraceSingle(GetWorld(), StartPos, EndPos, 70.0f, UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility), false, TArray<AActor*>(), DebugTrace, HitResult, true);
	ProcessTraceResult(HitResult);
}

void ATantrumCharacterBase::LineCastActorTransform()
{

	FVector StartPos = GetActorLocation();
	FVector EndPos = StartPos + (GetActorForwardVector() * 1000.0f);
	FHitResult HitResult;
	GetWorld() ? GetWorld()->LineTraceSingleByChannel(HitResult, StartPos, EndPos, ECollisionChannel::ECC_Visibility) : false;
#if ENABLE_DRAW_DEBUG
	if (CVarDisplayTrace->GetBool())
	{
		DrawDebugLine(GetWorld(), StartPos, EndPos, HitResult.bBlockingHit ? FColor::Red : FColor::White, false);
	}
#endif
	ProcessTraceResult(HitResult);
}

void ATantrumCharacterBase::ProcessTraceResult(const FHitResult& HitResult, bool bHighlight /* = true*/)
{
	//check if there was an existing throwable actor
	//remove the hightlight to avoid wrong feedback 
	AThrowableActor* HitThrowableActor = HitResult.bBlockingHit ? Cast<AThrowableActor>(HitResult.GetActor()) : nullptr;
	const bool IsSameActor = (ThrowableActor == HitThrowableActor);
	const bool IsValidTarget = HitThrowableActor && HitThrowableActor->IsIdle();

	//clean up old actor
	if (ThrowableActor && (!IsValidTarget || !IsSameActor))
	{
		ThrowableActor->ToggleHighlight(false);
		ThrowableActor = nullptr;
	}

	//no target, early out
	if (!IsValidTarget)
	{
		return;
	}

	//new target, set the variable and proceed
	if (!IsSameActor)
	{
		ThrowableActor = HitThrowableActor;
		if (bHighlight)
		{
			ThrowableActor->ToggleHighlight(true);
		}
	}

	if (CharacterThrowState == ECharacterThrowState::RequestingPull)
	{
		//don't allow for pulling objects while running/jogging
		if (GetVelocity().SizeSquared() < 100.0f)
		{
			ServerPullObject(ThrowableActor);
			CharacterThrowState = ECharacterThrowState::Pulling;
			ThrowableActor->ToggleHighlight(false);
			
		}
	}
}

bool ATantrumCharacterBase::PlayThrowMontage()
{
	const float PlayRate = 1.0f;
	bool bPlayedSuccessfully = PlayAnimMontage(ThrowMontage, PlayRate) > 0.f;
	if (bPlayedSuccessfully)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

		if (!BlendingOutDelegate.IsBound())
		{
			BlendingOutDelegate.BindUObject(this, &ATantrumCharacterBase::OnMontageBlendingOut);
		}
		AnimInstance->Montage_SetBlendingOutDelegate(BlendingOutDelegate, ThrowMontage);

		if (!MontageEndedDelegate.IsBound())
		{
			MontageEndedDelegate.BindUObject(this, &ATantrumCharacterBase::OnMontageEnded);
		}
		AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate, ThrowMontage);

		if (IsLocallyControlled())
		{
			AnimInstance->OnPlayMontageNotifyBegin.AddDynamic(this, &ATantrumCharacterBase::OnNotifyBeginReceived);
			AnimInstance->OnPlayMontageNotifyEnd.AddDynamic(this, &ATantrumCharacterBase::OnNotifyEndReceived);
		}

	}

	return bPlayedSuccessfully;
}

bool ATantrumCharacterBase::PlayCelebrateMontage()
{
	const float PlayRate = 1.0f;
	bool bPlayedSuccessfully = PlayAnimMontage(CelebrateMontage, PlayRate) > 0.f;
	if (bPlayedSuccessfully)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

		if (!MontageEndedDelegate.IsBound())
		{
			MontageEndedDelegate.BindUObject(this, &ATantrumCharacterBase::OnMontageEnded);
		}
		AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate, CelebrateMontage);
	}

	return bPlayedSuccessfully;
}


void ATantrumCharacterBase::ServerPlayCelebrateMontage_Implementation()
{
	MulticastPlayCelebrateMontage();
}

void ATantrumCharacterBase::MulticastPlayCelebrateMontage_Implementation()
{
	PlayCelebrateMontage();
}

void ATantrumCharacterBase::UpdateThrowMontagePlayRate()
{
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		if (UAnimMontage* CurrentAnimMontage = AnimInstance->GetCurrentActiveMontage())
		{
			//speed up the playrate when at the throwing part of the animation, as the initial interaction animation wasn't intended as a throw so it's rather slow
			const float PlayRate = AnimInstance->GetCurveValue(TEXT("ThrowCurve"));
			AnimInstance->Montage_SetPlayRate(CurrentAnimMontage, PlayRate);
		}
	}
}

void ATantrumCharacterBase::UnbindMontage()
{
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		AnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic(this, &ATantrumCharacterBase::OnNotifyBeginReceived);
		AnimInstance->OnPlayMontageNotifyEnd.RemoveDynamic(this, &ATantrumCharacterBase::OnNotifyEndReceived);
	}
}

void ATantrumCharacterBase::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{

}

void ATantrumCharacterBase::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (IsLocallyControlled())
	{
		UnbindMontage();
	}

	if (Montage == ThrowMontage)
	{
		if (IsLocallyControlled())
		{
			CharacterThrowState = ECharacterThrowState::None;
			ServerFinishThrow();
			ThrowableActor = nullptr;
		}
	}
	else if (Montage == CelebrateMontage)
	{
		if (IsLocallyControlled())
		{
			//this shouldn't be here...
			//display hud, we don't want this for all, so we should broadcast and whoever is intereseted can listen...
			if (UTantrumGameInstance* TantrumGameInstance = GetWorld()->GetGameInstance<UTantrumGameInstance>())
			{
				ATantrumPlayerController* TantrumPlayerController = GetController<ATantrumPlayerController>();
				if (TantrumPlayerController)
				{
					TantrumGameInstance->DisplayLevelComplete(TantrumPlayerController);
				}

			}
		}

		if (ATantrumPlayerState* TantrumPlayerState = GetPlayerState<ATantrumPlayerState>())
		{
			if (TantrumPlayerState->IsWinner())
			{
				PlayAnimMontage(CelebrateMontage, 1.0f, TEXT("Winner"));
			}
		}

	}
}

void ATantrumCharacterBase::OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{
	//do this on server, since server owns the object we are throwing...
	ServerBeginThrow();
}


void ATantrumCharacterBase::OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{

}

void ATantrumCharacterBase::OnStunBegin(float StunRatio)
{
	if (bIsStunned)
	{
		//for now just early exit, alternative option would be to add to the stun time
		return;
	}

	const float StunDelt = MaxStunTime - MinStunTime;
	StunTime = MinStunTime + (StunRatio * StunDelt);
	CurrentStunTimer = 0.0f;
	//StunBeginTimestamp = FApp::GetCurrentTime();
	bIsStunned = true;
	if (bIsSprinting)
	{
		RequestSprintEnd();
	}
	GetMesh();
}

void ATantrumCharacterBase::UpdateStun(float DeltaTime)
{
	if (bIsStunned)
	{
		CurrentStunTimer += DeltaTime;
		bIsStunned = CurrentStunTimer > StunTime;
		//bIsStunned = (FApp::GetCurrentTime() - StunBeginTimestamp) < StunTime;
		if (!bIsStunned)
		{
			OnStunEnd();
		}
	}
}

void ATantrumCharacterBase::OnStunEnd()
{
	CurrentStunTimer = 0.0f;
	//StunBeginTimestamp = 0.0f;
	StunTime = 0.0f;
}

//this can be done locally and the server will update the correct position?
void ATantrumCharacterBase::UpdateRescue(float DeltaTime)
{
	CurrentRescueTime += DeltaTime;
	float Alpha = FMath::Clamp(CurrentRescueTime / TimeToRescuePlayer, 0.0f, 1.0f);
	FVector NewPlayerLocation = FMath::Lerp(FallOutOfWorldPosition, LastGroundPosition, Alpha);
	SetActorLocation(NewPlayerLocation);

	if (HasAuthority())
	{
		if (Alpha >= 1.0f)
		{
			EndRescue();
		}
	}

}

void ATantrumCharacterBase::StartRescue()
{
	//this will be broadcasted, don't want to potentially start moving to a bad location
	bIsBeingRescued = true;
	FallOutOfWorldPosition = GetActorLocation();
	CurrentRescueTime = 0.0f;
	GetCharacterMovement()->Deactivate();
	SetActorEnableCollision(false);
}

void ATantrumCharacterBase::OnRep_IsBeingRescued()
{
	if (bIsBeingRescued)
	{
		StartRescue();
	}
	else
	{
		EndRescue();
	}
}

void ATantrumCharacterBase::EndRescue()
{
	//authority will dictate when this is over
	bIsBeingRescued = false;
	GetCharacterMovement()->Activate();
	SetActorEnableCollision(true);
	CurrentRescueTime = 0.0f;
}

void ATantrumCharacterBase::OnRep_CharacterThrowState(const ECharacterThrowState& OldCharacterThrowState)
{
	if (CharacterThrowState != OldCharacterThrowState)
	{
		UE_LOG(LogTemp, Warning, TEXT("OldThrowState: %s"), *UEnum::GetDisplayValueAsText(OldCharacterThrowState).ToString());
		UE_LOG(LogTemp, Warning, TEXT("CharacterThrowState: %s"), *UEnum::GetDisplayValueAsText(CharacterThrowState).ToString());
	}
}

void ATantrumCharacterBase::ApplyEffect_Implementation(EEffectType EffectType, bool bIsBuff)
{
	if (bIsUnderEffect) return;

	CurrentEffect = EffectType;
	bIsUnderEffect = true;
	bIsEffectBuff = bIsBuff;

	switch (CurrentEffect)
	{
	case EEffectType::Speed:
		//bIsEffectBuff ? SprintSpeed *= 2 : GetCharacterMovement()->DisableMovement();
		break;
	case EEffectType::Jump:
		// Implement Jump Buff/Debuff
		break;
	case EEffectType::Power:
		// Implement Power Buff/Debuff
		break;
	default:
		break;
	}
}

void ATantrumCharacterBase::UpdateEffect(float DeltaTime)
{
	if (EffectCooldown > 0)
	{
		EffectCooldown -= DeltaTime;
	}
	else
	{
		bIsUnderEffect = false;
		EffectCooldown = DefautlEffectCooldown;
		EndEffect();
	}
}

void ATantrumCharacterBase::EndEffect()
{
	bIsUnderEffect = false;
	switch (CurrentEffect)
	{
	case EEffectType::Speed:
		bIsEffectBuff ? SprintSpeed /= 2, RequestSprintEnd() : GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		break;
	case EEffectType::Jump:
		// Implement Jump Buff/Debuff
		break;
	case EEffectType::Power:
		// Implement Power Buff/Debuff
		break;
	default:
		break;
	}
}
