// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TantrumCharacterBase.h"
#include "TantrumGameModeBase.h"
#include "TantrumGameInstance.h"
#include "TantrumGameStateBase.h"
#include "TantrumPlayerState.h"

static TAutoConsoleVariable<bool> CVarDisplayLaunchInputDelta(
	TEXT("Tantrum.Character.Debug.DisplayLaunchInputDelta"),
	false,
	TEXT("Display Launch Input Delta"),
	ECVF_Default);

void ATantrumPlayerController::BeginPlay()
{
	Super::BeginPlay();
	TantrumGameState = GetWorld()->GetGameState<ATantrumGameStateBase>();
	//ensureMsgf(TantrumGameState, TEXT("ATantrumPlayerController::BeginPlay Invalid TantrumGameState"));
}
//called from gamemode, so only on authority will we get these calls
void ATantrumPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	UE_LOG(LogTemp, Warning, TEXT("OnPossess: %s"), *GetName());
}

void ATantrumPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	UE_LOG(LogTemp, Warning, TEXT("OnUnPossess: %s"), *GetName());
}

void ATantrumPlayerController::ClientDisplayCountdown_Implementation(float GameCountdownDuration)
{
	if (UTantrumGameInstance* TantrumGameInstance = GetWorld()->GetGameInstance<UTantrumGameInstance>())
	{
		TantrumGameInstance->DisplayCountdown(GameCountdownDuration, this);
	}
}

void ATantrumPlayerController::ClientRestartGame_Implementation()
{
	if (ATantrumPlayerState* TantrumPlayerState = GetPlayerState<ATantrumPlayerState>())
	{
		if (UTantrumGameInstance* TantrumGameInstance = GetWorld()->GetGameInstance<UTantrumGameInstance>())
		{
			TantrumGameInstance->RestartGame(this);
		}
	}
}

void ATantrumPlayerController::ClientReachedEnd_Implementation()
{
	//this needs to be named better, it's just displaying the end screen
	//this will be seperate, as it will come after the montage...
	//client gets hud authority needs to replicate the montage

	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->ServerPlayCelebrateMontage();
		TantrumCharacterBase->GetCharacterMovement()->DisableMovement();
	}

	if (UTantrumGameInstance* TantrumGameInstance = GetWorld()->GetGameInstance<UTantrumGameInstance>())
	{
		//call the level complete event for the widget...
	}

	FInputModeUIOnly InputMode;
	SetInputMode(InputMode);
	SetShowMouseCursor(true);
}

void ATantrumPlayerController::ServerRestartLevel_Implementation()
{
	//GetWorld()->ServerTravel(TEXT("?restart"));
	ATantrumGameModeBase* TantrumGameMode = GetWorld()->GetAuthGameMode<ATantrumGameModeBase>();
	if (ensureMsgf(TantrumGameMode, TEXT("ATantrumPlayerController::ServerRestartLevel_Implementation Invalid GameMode")))
	{
		TantrumGameMode->RestartGame();

	}
	/*RestartPlayer()
	GetWorld()->GetCurrentLevel()->GetName()
	GetWorld()->ServerTravel(TEXT("?restart"));*/
}

void ATantrumPlayerController::ReceivedPlayer()
{
	Super::ReceivedPlayer();

	if (IsLocalController())
	{
		if (HUDClass)
		{
			HUDWidget = CreateWidget(this, HUDClass);
			if (HUDWidget)
			{
				//HUDWidget->AddToViewport();
				HUDWidget->AddToPlayerScreen();
			}
		}
	}

}

void ATantrumPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ATantrumPlayerController::RequestJump);
		InputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Released, this, &ATantrumPlayerController::RequestStopJump);

		InputComponent->BindAction(TEXT("Crouch"), EInputEvent::IE_Pressed, this, &ATantrumPlayerController::RequestCrouchStart);
		InputComponent->BindAction(TEXT("Crouch"), EInputEvent::IE_Released, this, &ATantrumPlayerController::RequestCrouchEnd);
		InputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &ATantrumPlayerController::RequestSprintStart);
		InputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &ATantrumPlayerController::RequestSprintEnd);

		InputComponent->BindAction(TEXT("PullorAimObject"), EInputEvent::IE_Pressed, this, &ATantrumPlayerController::RequestPullorAimObject);
		InputComponent->BindAction(TEXT("PullorAimObject"), EInputEvent::IE_Released, this, &ATantrumPlayerController::RequestStopPullorAimObject);

		InputComponent->BindAxis(TEXT("MoveForward"), this, &ATantrumPlayerController::RequestMoveForward);
		InputComponent->BindAxis(TEXT("MoveRight"), this, &ATantrumPlayerController::RequestMoveRight);
		InputComponent->BindAxis(TEXT("LookUp"), this, &ATantrumPlayerController::RequestLookUp);
		InputComponent->BindAxis(TEXT("LookRight"), this, &ATantrumPlayerController::RequestLookRight);
		InputComponent->BindAxis(TEXT("ThrowObject"), this, &ATantrumPlayerController::RequestThrowObject);

	}
}

bool ATantrumPlayerController::CanProcessRequest() const
{
	if (TantrumGameState && TantrumGameState->IsPlaying())
	{
		if (ATantrumPlayerState* TantrumPlayerState = GetPlayerState<ATantrumPlayerState>())
		{
			return (TantrumPlayerState->GetCurrentState() == EPlayerGameState::Playing);
		}
	}

	return false;
}

void ATantrumPlayerController::RequestMoveForward(float AxisValue)
{
	if (!CanProcessRequest())
	{
		return;
	}

	if (AxisValue != 0.f)
	{
		FRotator const ControlSpaceRot = GetControlRotation();
		// transform to world space and add it
		GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), AxisValue);
	}
}

void ATantrumPlayerController::RequestMoveRight(float AxisValue)
{
	if (!CanProcessRequest())
	{
		return;
	}

	if (AxisValue != 0.f)
	{
		FRotator const ControlSpaceRot = GetControlRotation();
		// transform to world space and add it
		GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), AxisValue);
	}
}

void ATantrumPlayerController::RequestLookUp(float AxisValue)
{
	AddPitchInput(AxisValue * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATantrumPlayerController::RequestLookRight(float AxisValue)
{
	AddYawInput(AxisValue * BaseLookRightRate * GetWorld()->GetDeltaSeconds());
}

void ATantrumPlayerController::RequestThrowObject(float AxisValue)
{
	if (!CanProcessRequest())
	{
		return;
	}

	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		if (TantrumCharacterBase->CanThrowObject())
		{
			float currentDelta = AxisValue - LastAxis;

			//debug
			if (CVarDisplayLaunchInputDelta->GetBool())
			{
				if (fabs(currentDelta) > 0.0f)
				{
					UE_LOG(LogTemp, Warning, TEXT("Axis: %f LastAxis: %f currentDelta: %f"), AxisValue, LastAxis, currentDelta);
				}
			}
			LastAxis = AxisValue;
			const bool IsFlick = fabs(currentDelta) > FlickThreshold;
			if (IsFlick)
			{
				if (currentDelta > 0)
				{
					TantrumCharacterBase->RequestThrowObject();
				}
				else
				{
					TantrumCharacterBase->RequestUseObject();
				}
			}
		}
		else
		{
			LastAxis = 0.0f;
		}
	}
}

void ATantrumPlayerController::RequestPullorAimObject()
{
	if (!CanProcessRequest())
	{
		return;
	}

	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
		if (TantrumCharacterBase->CanAim())
		{
			TantrumCharacterBase->RequestAim();
		}
		else
		{
			TantrumCharacterBase->RequestPullObject();
		}
}

void ATantrumPlayerController::RequestStopPullorAimObject()
{
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->RequestStopPullObject();
	}
}

void ATantrumPlayerController::RequestJump()
{
	if (!CanProcessRequest())
	{
		return;
	}

	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->Jump();

		//SoundCue Triggers
		if (JumpSound && TantrumCharacterBase->GetCharacterMovement()->IsMovingOnGround())
		{
			FVector CharacterLocation = TantrumCharacterBase->GetActorLocation();
			UGameplayStatics::PlaySoundAtLocation(this, JumpSound, CharacterLocation);
		}
	}
}

void ATantrumPlayerController::RequestStopJump()
{
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->StopJumping();
	}
}

void ATantrumPlayerController::RequestCrouchStart()
{
	if (!CanProcessRequest())
	{
		return;
	}

	ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter());
	if (!TantrumCharacterBase || !TantrumCharacterBase->GetCharacterMovement()->IsMovingOnGround())
	{
		return;
	}

	TantrumCharacterBase->Crouch();
}

void ATantrumPlayerController::RequestCrouchEnd()
{
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->UnCrouch();
	}
}

void ATantrumPlayerController::RequestSprintStart()
{
	if (!CanProcessRequest())
	{
		return;
	}

	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->RequestSprintStart();
	}
}

void ATantrumPlayerController::RequestSprintEnd()
{
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->RequestSprintEnd();
	}
}