// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TantrumCharacterBase.h"
#include "TantrumGameModeBase.h"

static TAutoConsoleVariable<bool> CVarDisplayLaunchInputDelta(
	TEXT("Tantrum.Character.Debug.DisplayLaunchInputDelta"),
	false,
	TEXT("Display Launch Input Delta"),
	ECVF_Default);

void ATantrumPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//GameModeRef = Cast<ATantrumGameModeBase>(GetWorld()->GetAuthGameMode());

}

void ATantrumPlayerController::ReceivedPlayer()
{
	Super::ReceivedPlayer();
	GameModeRef = GetWorld()->GetAuthGameMode<ATantrumGameModeBase>();
	if (ensureMsgf(GameModeRef, TEXT("ATantrumPlayerController::ReceivedPlayer missing GameMode Reference")))
	{
		GameModeRef->ReceivePlayer(this);
	}

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

		InputComponent->BindAction(TEXT("PullObject"), EInputEvent::IE_Pressed, this, &ATantrumPlayerController::RequestPullObject);
		InputComponent->BindAction(TEXT("PullObject"), EInputEvent::IE_Released, this, &ATantrumPlayerController::RequestStopPullObject);

		InputComponent->BindAxis(TEXT("MoveForward"), this, &ATantrumPlayerController::RequestMoveForward);
		InputComponent->BindAxis(TEXT("MoveRight"), this, &ATantrumPlayerController::RequestMoveRight);
		InputComponent->BindAxis(TEXT("LookUp"), this, &ATantrumPlayerController::RequestLookUp);
		InputComponent->BindAxis(TEXT("LookRight"), this, &ATantrumPlayerController::RequestLookRight);
		InputComponent->BindAxis(TEXT("ThrowObject"), this, &ATantrumPlayerController::RequestThrowObject);

	}
}

void ATantrumPlayerController::RequestMoveForward(float AxisValue)
{
	/*if(!GameModeRef || GameModeRef->GetCurrentGameState() != EGameState::Playing)
	{
		return;
	}*/

	if (AxisValue != 0.f)
	{
		FRotator const ControlSpaceRot = GetControlRotation();
		// transform to world space and add it
		GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), AxisValue);
	}
}

void ATantrumPlayerController::RequestMoveRight(float AxisValue)
{
	/*if(!GameModeRef || GameModeRef->GetCurrentGameState() != EGameState::Playing)
	{
		return;
	}*/

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

void ATantrumPlayerController::RequestPullObject()
{
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->RequestPullObject();
	}
}

void ATantrumPlayerController::RequestStopPullObject()
{
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->RequestStopPullObject();
	}
}

void ATantrumPlayerController::RequestJump()
{
	//create a function for this
	//if(!GameModeRef || GameModeRef->GetCurrentGameState() != EGameState::Playing) 
	//{
	//	return;
	//}
	if (GetCharacter())
	{
		GetCharacter()->Jump();

		//SoundCue Triggers
		if (JumpSound && GetCharacter()->GetCharacterMovement()->IsMovingOnGround())
		{
			FVector CharacterLocation = GetCharacter()->GetActorLocation();
			UGameplayStatics::PlaySoundAtLocation(this, JumpSound, CharacterLocation);
		}
	}
}

void ATantrumPlayerController::RequestStopJump()
{
	if (GetCharacter())
	{
		GetCharacter()->StopJumping();
	}
}

void ATantrumPlayerController::RequestCrouchStart()
{
	/*if(!GameModeRef || GameModeRef->GetCurrentGameState() != EGameState::Playing)
	{
		return;
	}*/

	if (!GetCharacter()->GetCharacterMovement()->IsMovingOnGround()) { return; }
	if (GetCharacter())
	{
		GetCharacter()->Crouch();
	}
}

void ATantrumPlayerController::RequestCrouchEnd()
{
	if (GetCharacter())
	{
		GetCharacter()->UnCrouch();
	}
}

void ATantrumPlayerController::RequestSprintStart()
{
	//if(!GameModeRef || GameModeRef->GetCurrentGameState() != EGameState::Playing) 
	//{
	//	return;
	//}
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