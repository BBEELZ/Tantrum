// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TantrumGameWidget.h"
#include "GameFramework/GameModeBase.h"
#include "TantrumGameModeBase.generated.h"

//Enum to track the current state of the game
UENUM(BlueprintType)
enum class EGameState : uint8
{
	NONE		UMETA(DisplayName = "None"),
	Waiting		UMETA(DisplayName = "Waiting"),
	Playing		UMETA(DisplayName = "Playing"),
	Paused		UMETA(DisplayName = "Paused"),
	GameOver	UMETA(DisplayName = "GameOver"),
};

UCLASS()
class TANTRUM_API ATantrumGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	// --- FUNCTIONS --- //
	ATantrumGameModeBase();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	EGameState GetCurrentGameState() const;
	void PlayerReachedEnd();


private:

	// --- VARS --- //

	// Create and set CUrrentGameState to NONE. This will be tracked in the code file.
	UPROPERTY(VisibleAnywhere, Category = "States")
	EGameState CurrentGameState = EGameState::NONE;

	// Countdown before gameplay state begins. Exposed so we can easily change this in BP editor.
	UPROPERTY(EditAnywhere, Category = "Game Details")
	float GameCountdownDuration = 4.0f;

	FTimerHandle TimerHandle;

	UPROPERTY()
	UTantrumGameWidget* GameWidget; // Object we'll be creating and addin to the viewport
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UTantrumGameWidget> GameWidgetClass; // Exposed class to check the type of widget to display

	APlayerController* PC = nullptr;

	// --- FUNCTIONS --- //

	void DisplayCountdown();
	void StartGame();
	
};