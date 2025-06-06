#pragma once
#include "TileStruct.h"
#include "DynamicArray.h"
#include <string>
#include <sstream>

using namespace std;

class Board
{
private:

	Board();
	static Board* singleton;

	TileStruct* gameBoard[10][10];
	vector<string> fenHistory;
	int turnCounter;
	int kingMovesCounter;

public:

	//Getter and Setters
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	static Board* GetBoardSingleton();

	TileStruct* GetTile(int row, int column);
	TileStruct* GetTile(const PositionStruct& position);

	// Board logic
	string LoadBoard(string FEN);
	void setupMen(string MenLayout, bool bWhite);
	void MoveMen(PositionStruct men, PositionStruct destination);
	void CheckMenBecomeKing(const PositionStruct& men);
	void UpdateFEN(const string& playerTurn);
	string GetMenLayout();
	string GetAndUpdateAmountOfTurn(bool blackPlayerTurn);
	void DisplayBoard();
};

