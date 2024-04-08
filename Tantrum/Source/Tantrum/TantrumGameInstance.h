// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TantrumGameInstance.generated.h"

class ATantrumPlayerController;
class ATantrumGameStateBase;
class UTantrumGameWidget;

UCLASS()
class TANTRUM_API UTantrumGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	void DisplayCountdown(float GameCountdownDuration, ATantrumPlayerController* TantrumPlayerController);
	void DisplayLevelComplete(ATantrumPlayerController* TantrumPlayerController);

	UFUNCTION(BlueprintPure)
	ATantrumGameStateBase* GetGameState() const { return TantrumGameStateBase; }

	UFUNCTION(BlueprintCallable)
	void OnRetrySelected(ATantrumPlayerController* TantrumPlayerController);

	UFUNCTION()
	void RestartGame(ATantrumPlayerController* TantrumPlayerController);
protected:
	UFUNCTION()
	void OnGameStateSet(AGameStateBase* GameStateBase);

private:
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UTantrumGameWidget> GameWidgetClass; // Exposed class to check the type of widget to display

	UPROPERTY()
	TMap<APlayerController*, UTantrumGameWidget*> GameWidgets;

	UPROPERTY()
	ATantrumGameStateBase* TantrumGameStateBase;
};
