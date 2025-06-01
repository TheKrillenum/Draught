#pragma once
#include "TileStruct.h"
#include "DynamicArray.h"
#include <string>

using namespace std;

class Board
{
private:

	Board();
	static Board* singleton;

	TileStruct* gameBoard[10][10];
	DynamicArray<string> fenHistory;
	int turnCounter;
	int kingMovesCounter;

public:

	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	static Board* GetBoardSingleton();

	void Test();

	TileStruct* GetTile(PositionStruct position);
	void LoadBoard(string FEN);
	void MoveMen(PositionStruct men, PositionStruct destination);
	void CheckMenBecomeKing(PositionStruct men);
	string UpdateFEN(string playerTurn, bool isCurrentPlayerWhite);
	string GetMenLayout();
	string GetAndUpdateAmountOfTurn(bool isCurrentPlayerWhite);
	void DisplayBoard();
};

