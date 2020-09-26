// KKrupa UJ 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ScoreSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class VRKANOID_API UScoreSaveGame : public USaveGame
{
	GENERATED_BODY()


public:

	static UScoreSaveGame* Create();
	
	bool Save();

	static UScoreSaveGame* Load();


	void SetScores(TArray<int32> NewScores) { Scores = NewScores; }
	TArray<int32> GetScores() const { return Scores; }

private:
	//State
	UPROPERTY()
		TArray<int32> Scores;
};

