// Copyright Epic Games, Inc. All Rights Reserved.


#include "TantrumGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

ATantrumGameModeBase::ATantrumGameModeBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATantrumGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentGameState = EGameState::Waiting;
}

void ATantrumGameModeBase::ReceivePlayer(APlayerController* PlayerController)
{
	AttemptStartGame();
}

EGameState ATantrumGameModeBase::GetCurrentGameState() const
{
	return CurrentGameState;
}

void ATantrumGameModeBase::PlayerReachedEnd(APlayerController* PlayerController)
{
	//one gamemode base is shared between players in local mp
	CurrentGameState = EGameState::GameOver;
	UTantrumGameWidget** GameWidget = GameWidgets.Find(PlayerController);
	if (GameWidget)
	{
		(*GameWidget)->LevelComplete();
		FInputModeUIOnly InputMode;
		PlayerController->SetInputMode(InputMode);
		PlayerController->SetShowMouseCursor(true);
		if (PlayerController->GetCharacter() && PlayerController->GetCharacter()->GetCharacterMovement())
		{
			PlayerController->GetCharacter()->GetCharacterMovement()->DisableMovement();
		}
	}
}

void ATantrumGameModeBase::AttemptStartGame()
{
	if (GetNumPlayers() == NumExpectedPlayers)
	{
		DisplayCountdown();
		if (GameCountdownDuration > SMALL_NUMBER)
		{
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATantrumGameModeBase::StartGame, GameCountdownDuration, false);
		}
		else
		{
			StartGame();
		}

	}
}

void ATantrumGameModeBase::DisplayCountdown()
{
	if (!GameWidgetClass)
	{
		return;
	}

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if (PlayerController && PlayerController->PlayerState && !MustSpectate(PlayerController))
		{
			if (UTantrumGameWidget* GameWidget = CreateWidget<UTantrumGameWidget>(PlayerController, GameWidgetClass))
			{
				//GameWidget->AddToViewport();
				GameWidget->AddToPlayerScreen();
				GameWidget->StartCountdown(GameCountdownDuration, this);
				GameWidgets.Add(PlayerController, GameWidget);
			}
		}
	}
}

void ATantrumGameModeBase::StartGame()
{
	CurrentGameState = EGameState::Playing;
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if (PlayerController && PlayerController->PlayerState && !MustSpectate(PlayerController))
		{
			FInputModeGameOnly InputMode;
			PlayerController->SetInputMode(InputMode);
			PlayerController->SetShowMouseCursor(false);
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
		}
	}
}
