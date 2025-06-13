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

	bool gameOngoing;

	string DefaultFEN;

public: 

	GameManager();
	void StartGame();
	void PlayGame();
	void PlayTurn();
	PositionStruct PlayerReturnChosenMen(const vector<PositionStruct>& menToChoose);
	PositionStruct PlayerReturnChosenDestination(PositionStruct chosenMen, vector<PositionStruct> availableMen);
	bool CheckGameIsWon();
	bool CheckGameIsDraw();
	bool CheckAmountOfKingMoves();
	bool CheckRepetitionFEN();
	void SwitchCurrentPlayer();
	void DrawGame();
	void EndGame(Player winner);

	void GetCurrentPlayer();

	void removeWhiteSpace(string& inputLine);
	bool getValidPlayerInput(PositionStruct& position);

};

