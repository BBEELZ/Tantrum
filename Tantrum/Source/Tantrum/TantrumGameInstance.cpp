// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumGameInstance.h"
#include "TantrumGameWidget.h"
#include "TantrumGameStateBase.h"
#include "TantrumPlayerController.h"

void UTantrumGameInstance::DisplayCountdown(float GameCountdownDuration, ATantrumPlayerController* TantrumPlayerController)
{
	if (GetWorld())
	{
		UTantrumGameWidget* PlayerGameWidget = nullptr;
		UTantrumGameWidget** GameWidget = GameWidgets.Find(TantrumPlayerController);
		if (GameWidget == nullptr)
		{
			PlayerGameWidget = CreateWidget<UTantrumGameWidget>(TantrumPlayerController, GameWidgetClass);
			if (PlayerGameWidget)
			{
				//only do this once
				//atm we never remove this as it has the race time
				PlayerGameWidget->AddToPlayerScreen();
				GameWidgets.Add(TantrumPlayerController, PlayerGameWidget);
			}
		}
		else
		{
			PlayerGameWidget = *GameWidget;
		}

		if (PlayerGameWidget)
		{
			PlayerGameWidget->StartCountdown(GameCountdownDuration, TantrumPlayerController);
			TantrumGameStateBase = GetWorld()->GetGameState<ATantrumGameStateBase>();
			if (!TantrumGameStateBase)
			{
				GetWorld()->GameStateSetEvent.AddUObject(this, &UTantrumGameInstance::OnGameStateSet);
			}
		}
	}
}

void UTantrumGameInstance::OnGameStateSet(AGameStateBase* GameStateBase)
{
	TantrumGameStateBase = Cast<ATantrumGameStateBase>(GameStateBase);
}

void UTantrumGameInstance::DisplayLevelComplete(ATantrumPlayerController* TantrumPlayerController)
{
	UTantrumGameWidget** GameWidget = GameWidgets.Find(TantrumPlayerController);
	if (GameWidget)
	{
		(*GameWidget)->DisplayResults();
	}
}

void UTantrumGameInstance::RestartGame(ATantrumPlayerController* TantrumPlayerController)
{
	UTantrumGameWidget** GameWidget = GameWidgets.Find(TantrumPlayerController);
	if (GameWidget)
	{
		(*GameWidget)->RemoveResults();
		//restore game input 
		FInputModeGameOnly InputMode;
		TantrumPlayerController->SetInputMode(InputMode);
		TantrumPlayerController->SetShowMouseCursor(false);
	}

}

void UTantrumGameInstance::OnRetrySelected(ATantrumPlayerController* TantrumPlayerController)
{
	UTantrumGameWidget** GameWidget = GameWidgets.Find(TantrumPlayerController);
	if (GameWidget)
	{
		RestartGame(TantrumPlayerController);
		TantrumPlayerController->ServerRestartLevel();
	}
}