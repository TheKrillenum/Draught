#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

class Board
{
private:

	// Singelton
	Board();
	static Board* singleton;

	struct TileStruct* gameBoard[10][10];
	vector<string>* fenHistory;
	int turnCounter;
	int kingMovesCounter;

	// For visuals
	HANDLE hConsole; 

public:

	//Singelton
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	static Board* GetBoardSingleton();

	// Board logic
	string LoadBoard(string FEN);
	void setupMen(string WhiteLayout, string BlackLayout);
	void MoveMen(struct PositionStruct men, struct PositionStruct destination, bool menCountForKingMove);
	void CheckMenBecomeKing(const struct PositionStruct& men);
	void UpdateFEN(const string& playerTurn);
	string GetMenLayout();
	string GetAndUpdateAmountOfTurn(bool blackPlayerTurn);
	void DisplayBoard();
	void ClearHighlightedTile();
	bool ValidPosition(const PositionStruct& PositionToCheck);

	// Getters and Setters
	int GetTurnCounter();
	int GetKingMoveCounter();
	vector<string>* GetFenHistory();
	struct TileStruct* GetTile(int row, int column);
	struct TileStruct* GetTile(const struct PositionStruct& position);
};

