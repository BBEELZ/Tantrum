// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumGameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "TantrumCharacterBase.h"
#include "TantrumPlayerController.h"
#include "TantrumPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TantrumAIController.h"

void ATantrumGameStateBase::UpdateResults(ATantrumPlayerState* PlayerState, ATantrumCharacterBase* TantrumCharacter)
{
	if (!PlayerState || !TantrumCharacter)
	{
		return;
	}

	const bool IsWinner = Results.Num() == 0;
	PlayerState->SetIsWinner(IsWinner);

	PlayerState->SetCurrentState(EPlayerGameState::Finished);

	FGameResult Result;
	Result.Name = TantrumCharacter->GetName();

	Result.Time = 5.0f;
	Results.Add(Result);
}

//only ever called by the authority
void ATantrumGameStateBase::OnPlayerReachedEnd(ATantrumCharacterBase* TantrumCharacter)
{
	ensureMsgf(HasAuthority(), TEXT("ATantrumGameStateBase::OnPlayerReachedEnd being called from Non Authority!"));

	if (ATantrumPlayerController* TantrumPlayerController = TantrumCharacter->GetController<ATantrumPlayerController>())
	{

		TantrumPlayerController->ClientReachedEnd();
		TantrumCharacter->GetCharacterMovement()->DisableMovement();
		ATantrumPlayerState* PlayerState = TantrumPlayerController->GetPlayerState<ATantrumPlayerState>();
		UpdateResults(PlayerState, TantrumCharacter);

		//TODO this will not work once JIP(Join In Progress) is enabled
		if (Results.Num() == PlayerArray.Num())
		{
			GameState = EGameState::GameOver;
		}
	}
	else if (ATantrumAIController* TantrumAIController = TantrumCharacter->GetController<ATantrumAIController>())
	{
		ATantrumPlayerState* PlayerState = TantrumAIController->GetPlayerState<ATantrumPlayerState>();
		UpdateResults(PlayerState, TantrumCharacter);
		TantrumAIController->OnReachedEnd();
	}
}

void ATantrumGameStateBase::ClearResults()
{
	Results.Empty();
}

void ATantrumGameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams SharedParams;
	SharedParams.bIsPushBased = true;
	//SharedParams.Condition = COND_SkipOwner;

	DOREPLIFETIME_WITH_PARAMS_FAST(ATantrumGameStateBase, GameState, SharedParams);
	DOREPLIFETIME_WITH_PARAMS_FAST(ATantrumGameStateBase, Results, SharedParams);

	//DOREPLIFETIME(ATantrumCharacterBase, CharacterThrowState);
}

void ATantrumGameStateBase::OnRep_GameState(const EGameState& OldGameState)
{
	UE_LOG(LogTemp, Warning, TEXT("OldGameState: %s"), *UEnum::GetDisplayValueAsText(OldGameState).ToString());
	UE_LOG(LogTemp, Warning, TEXT("GameState: %s"), *UEnum::GetDisplayValueAsText(GameState).ToString());
}