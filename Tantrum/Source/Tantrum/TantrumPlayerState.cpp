// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Net/Core/PushModel/PushModel.h"

void ATantrumPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams SharedParams;
	SharedParams.bIsPushBased = true;

	DOREPLIFETIME_WITH_PARAMS_FAST(ATantrumPlayerState, CurrentState, SharedParams);
	DOREPLIFETIME_WITH_PARAMS_FAST(ATantrumPlayerState, bIsWinner, SharedParams);
}