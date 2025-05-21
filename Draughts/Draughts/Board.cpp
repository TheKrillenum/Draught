#include <iostream>
#include "Board.h"

Board* Board::singleton = nullptr;

Board::Board()
{
	kingMovesCounter = 0;
	turnCounter = 0;

	string initFen = "W:W1,2,3,4,5";
	fenHistory.Add(initFen);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			gameBoard[i][j] = new TileStruct;
		}
	}
}

void Board::Hello()
{
	std::cout << "Hello Board !";
}

Board* Board::GetBoardSingleton()
{
	if (singleton == nullptr) {
		singleton = new Board();
	}

	return singleton;
}