// KKrupa UJ 2020


#include "ScoreSaveGame.h"
#include "Kismet/GameplayStatics.h"

UScoreSaveGame* UScoreSaveGame::Create()
{
	USaveGame* SaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	return Cast<UScoreSaveGame>(SaveGame);
}

bool UScoreSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Scores"), 0);
}

UScoreSaveGame* UScoreSaveGame::Load()
{
	return Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Scores"), 0));
}
