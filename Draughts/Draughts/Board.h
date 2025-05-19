#pragma once
#include "TileStruct.h"
#include <string>

using namespace std;

class Board
{
private:

	TileStruct* gameBoard;
	string fenHistory;
	int turnCounter;
	int kingMovesCounter;

public:

	Men* MoveMen(PositionStruct men, PositionStruct destination);
	void CheckMenBecomeKing(PositionStruct men);
	string UpdateFEN(string playerTurn);
	string GetMenLayout();
	string GetAndUpdateAmountOfTurn();

};

