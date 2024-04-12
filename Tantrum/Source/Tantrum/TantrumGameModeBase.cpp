// Copyright Epic Games, Inc. All Rights Reserved.


#include "TantrumGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TantrumGameInstance.h"
#include "TantrumGameStateBase.h"
#include "TantrumPlayerController.h"
#include "TantrumPlayerState.h"
#include "TantrumAIController.h"

ATantrumGameModeBase::ATantrumGameModeBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATantrumGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	if (ATantrumGameStateBase* TantrumGameState = GetGameState<ATantrumGameStateBase>())
	{
		TantrumGameState->SetGameState(EGameState::Waiting);
	}

}

void ATantrumGameModeBase::AttemptStartGame()
{
	if (ATantrumGameStateBase* TantrumGameState = GetGameState<ATantrumGameStateBase>())
	{
		TantrumGameState->SetGameState(EGameState::Waiting);
	}
	if (GetNumPlayers() == NumExpectedPlayers)
	{
		//this needs to be replicated, call a function on game instance and replicate
		DisplayCountdown();
		if (GameCountdownDuration > SMALL_NUMBER)
		{
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATantrumGameModeBase::StartGame, GameCountdownDuration, false);
		}
		else
		{
			//this is always called from the authority, aka here
			StartGame();
		}

	}
}
//this needs to be done on the game instance...
void ATantrumGameModeBase::DisplayCountdown()
{
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if (PlayerController && PlayerController->PlayerState && !MustSpectate(PlayerController))
		{
			if (ATantrumPlayerController* TantrumPlayerController = Cast< ATantrumPlayerController>(PlayerController))
			{
				TantrumPlayerController->ClientDisplayCountdown(GameCountdownDuration);
			}
		}
	}
}

void ATantrumGameModeBase::StartGame()
{
	if (ATantrumGameStateBase* TantrumGameState = GetGameState<ATantrumGameStateBase>())
	{
		TantrumGameState->SetGameState(EGameState::Playing);
		TantrumGameState->ClearResults();
	}

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if (PlayerController && PlayerController->PlayerState && !MustSpectate(PlayerController))
		{
			//cast and start?
			//this does not work on all controllers...
			FInputModeGameOnly InputMode;
			PlayerController->SetInputMode(InputMode);
			PlayerController->SetShowMouseCursor(false);

			ATantrumPlayerState* PlayerState = PlayerController->GetPlayerState<ATantrumPlayerState>();
			if (PlayerState)
			{
				PlayerState->SetCurrentState(EPlayerGameState::Playing);
				PlayerState->SetIsWinner(false);
			}
		}
	}
}

void ATantrumGameModeBase::RestartPlayer(AController* NewPlayer)
{
	Super::RestartPlayer(NewPlayer);

	if (APlayerController* PlayerController = Cast<APlayerController>(NewPlayer))
	{
		if (PlayerController->GetCharacter() && PlayerController->GetCharacter()->GetCharacterMovement())
		{
			PlayerController->GetCharacter()->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
			ATantrumPlayerState* PlayerState = PlayerController->GetPlayerState<ATantrumPlayerState>();
			if (PlayerState)
			{
				PlayerState->SetCurrentState(EPlayerGameState::Waiting);
			}
		}
	}

	AttemptStartGame();
}

void ATantrumGameModeBase::RestartGame()
{

	//destroy the actor
	for (FConstControllerIterator Iterator = GetWorld()->GetControllerIterator(); Iterator; ++Iterator)
	{
		ATantrumAIController* TantrumAIController = Cast<ATantrumAIController>(Iterator->Get());
		if (TantrumAIController && TantrumAIController->GetPawn())
		{
			TantrumAIController->Destroy(true);
		}
	}
	ResetLevel();
	//RestartGame();
	//GetWorld()->ServerTravel(TEXT("?Restart"), false);
	//ProcessServerTravel("?Restart");
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if (PlayerController && PlayerController->PlayerState && !MustSpectate(PlayerController))
		{
			//call something to clean up the hud 
			if (ATantrumPlayerController* TantrumPlayerController = Cast< ATantrumPlayerController>(PlayerController))
			{
				TantrumPlayerController->ClientRestartGame();
			}
			RestartPlayer(PlayerController);
		}
	}
}
