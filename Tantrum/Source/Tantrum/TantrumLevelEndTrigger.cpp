// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumLevelEndTrigger.h"
#include "TantrumCharacterBase.h"
#include "TantrumGameStateBase.h"

ATantrumLevelEndTrigger::ATantrumLevelEndTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ATantrumLevelEndTrigger::OnOverlapBegin);
}

void ATantrumLevelEndTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void ATantrumLevelEndTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (HasAuthority())
	{
		if (ATantrumGameStateBase* TantrumGameState = GetWorld()->GetGameState<ATantrumGameStateBase>())
		{
			ATantrumCharacterBase* TantrumCharacterBase = Cast<ATantrumCharacterBase>(OtherActor);
			TantrumGameState->OnPlayerReachedEnd(TantrumCharacterBase);
		}
	}

}
