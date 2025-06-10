#pragma once
#include "Board.h"
#include "Player.h"
#include "Men.h"
#include "PositionStruct.h"
#include <iostream>


class GameManager
{
private:

	Player* currentPlayer;
	Player* allPlayers[2];

	string DefaultFEN;

public: 

	GameManager();
	void StartGame();
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

	void GetCurrentPlayer();

};

