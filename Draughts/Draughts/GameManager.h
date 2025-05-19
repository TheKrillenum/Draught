#pragma once
#include "Player.h"
#include "PositionStruct.h"

class GameManager
{
private:

	Player* currentPlayer;
	Player* allPlayers;

public: 

	void PlayGame();
	void PlayTurn();
	PositionStruct PlayerReturnChosenMen(PositionStruct* menToChoose);
	PositionStruct PlayerReturnChosenDestination(PositionStruct chosenMen /* LegalEatingStruct availableDestination */);
	bool CheckGameIsWon();
	bool CheckGameIsDraw();
	bool CheckAmountOfKingMoves();
	bool CheckRepetitionFEN();
	void SwitchCurrentPlayer();
	void DrawGame();
	void EndGame(Player winner);

};

