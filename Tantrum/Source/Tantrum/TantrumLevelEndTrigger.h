// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "TantrumLevelEndTrigger.generated.h"

class ATantrumGameModeBase;

UCLASS(Blueprintable, BlueprintType)
class TANTRUM_API ATantrumLevelEndTrigger : public ATriggerVolume
{
	GENERATED_BODY()

public:

	ATantrumLevelEndTrigger();

protected:

	virtual void BeginPlay() override;

private:

	// Custom Overlap function to override the Actor BeginOverlap version. 
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

};
