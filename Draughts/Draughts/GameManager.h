#pragma once
#include "Board.h"
#include "Player.h"
#include "Men.h"
#include "PositionStruct.h"
#include <iostream>

enum KingMoveSituation {
	FullArmy,
	ThreeMen,
	LessThreeMen
};

class GameManager
{
private:

	Player* currentPlayer;
	Player* allPlayers[2];

	bool gameOngoing;
	KingMoveSituation situation;

	string DefaultFEN;

public: 

	GameManager();

	void StartGame();
	void PlayGame();
	void PlayTurn();

	PositionStruct PlayerReturnChosenMen(const vector<PositionStruct>& menToChoose);
	PositionStruct PlayerReturnChosenDestination(PositionStruct chosenDestination, vector<PositionStruct> availableDestination);

	bool CheckGameIsWon();
	bool CheckGameIsDraw();
	bool CheckAmountOfKingMoves();
	bool CheckRepetitionFEN();

	void SwitchCurrentPlayer();
	void DrawGame();
	void EndGame(Player winner);

	void removeWhiteSpace(string& inputLine);
	bool getValidPlayerInput(PositionStruct& position);
};

