// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumGameModeBase.h"

#include "Kismet/GameplayStatics.h"

ATantrumGameModeBase::ATantrumGameModeBase()
{

}

void ATantrumGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentGameState = EGameState::Waiting;
	DisplayCountdown();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATantrumGameModeBase::StartGame, GameCountdownDuration, false);
}

EGameState ATantrumGameModeBase::GetCurrentGameState() const
{
	return CurrentGameState;
}

void ATantrumGameModeBase::PlayerReachedEnd()
{
	CurrentGameState = EGameState::GameOver;
	// ToDo - Return to update widget.

	// ToDo - Return to control PlayerController Input state
}

void ATantrumGameModeBase::DisplayCountdown()
{
	if (!GameWidgetClass)
	{
		return;
	}

	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	GameWidget = CreateWidget<UTantrumGameWidget>(PC, GameWidgetClass);
	GameWidget->AddToViewport();
	GameWidget->StartCountdown(GameCountdownDuration, this);
}

void ATantrumGameModeBase::StartGame()
{
	CurrentGameState = EGameState::Playing;
}
