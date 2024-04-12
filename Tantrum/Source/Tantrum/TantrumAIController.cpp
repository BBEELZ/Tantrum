// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumAIController.h"
#include "TantrumCharacterBase.h"
#include "TantrumPlayerState.h"

void ATantrumAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(InPawn))
	{
		if (ATantrumPlayerState* TantrumPlayerState = GetPlayerState<ATantrumPlayerState>())
		{
			TantrumPlayerState->SetCurrentState(EPlayerGameState::Waiting);
		}
	}
}

void ATantrumAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ATantrumAIController::OnReachedEnd()
{
	if (ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(GetCharacter()))
	{
		TantrumCharacterBase->ServerPlayCelebrateMontage();
	}
}
