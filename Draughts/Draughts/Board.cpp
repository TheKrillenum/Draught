#include <iostream>
#include "Board.h"

Board* Board::singleton = nullptr;

Board::Board()
{
	// Initialise counter values
	kingMovesCounter = 0;
	turnCounter = 0;

	// loop through all 50 tiles of the board to initialise them. usableTile start
	// false since the first tile is unusable, and every other tile is also
	// unusable, so usableTile switches between true and false on each iteration.
	bool usableTile = false;
	int index = 1;

	for (int i = 0; i < 10; i++) {

		// for every even row, the first tile should be unusable
		// for every odd row,the first tile shoud be usable
		if (i % 2 == 0) {
			usableTile = false;
		}else {
			usableTile = true;
		}

		for (int j = 0; j < 10; j++) {
			
			if (usableTile) {
				// add the corresponding index to usable tiles and increment
				// index for next usable tile
				gameBoard[i][j] = new TileStruct{ index,nullptr };
				index++;
			}
			else {
				// set the index to -1 on unusable tiles
				gameBoard[i][j] = new TileStruct{-1,nullptr};
			}

			// Switch between usable and unusable tiles
			usableTile = (usableTile) ? false : true;
		}
	}
}

Board* Board::GetBoardSingleton()
{
	// Classic singleton
	if (singleton == nullptr) {
		singleton = new Board();
	}

	return singleton;
}

void Board::LoadBoard(string FEN)
{
	// Load the layout of the Men on the board based on the
	// provided FEN.
}

Men* Board::MoveMen(PositionStruct men, PositionStruct destination)
{
	return nullptr;
}

void Board::CheckMenBecomeKing(PositionStruct men)
{	
	// Check if a White men is on row [0] or if a black men
	// is on row [9]. If either is the case, transform said
	// men into a king.

	Men* menToCheck = gameBoard[men.row][men.column]->men;

	if (menToCheck->GetWhite()) {
		
		if (men.row == 0) {
			menToCheck->TransformToKing();
		}
	}
	else {
		if (men.row == 9) {
			menToCheck->TransformToKing();
		}
	}
}

string Board::UpdateFEN(string playerTurn)
{
	return string();
}

string Board::GetMenLayout()
{
	return string();
}

string Board::GetAndUpdateAmountOfTurn()
{
	return string();
}

void Board::DisplayBoard()
{
	for (int i = 0; i < 10; i++) {
		cout << "|";
		for (int j = 0; j < 10; j++) {

			if (gameBoard[i][j]->index != -1) {
				cout << gameBoard[i][j]->index << "\t|";
			}
			else {
				cout << " \t|";
			}
		}
		cout << endl;
	}
}