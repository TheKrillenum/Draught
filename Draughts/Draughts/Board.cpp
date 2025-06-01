#include <iostream>
#include "Board.h"

Board* Board::singleton = nullptr;

Board::Board()
{
	// Initialise counter values
	kingMovesCounter = 0;
	turnCounter = 1;

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

TileStruct* Board::GetTile(PositionStruct position)
{
	return gameBoard[position.row][position.column];
}

string Board::LoadBoard(string FEN)
{
	stringstream SSFEN;
	SSFEN << FEN;

	string newCurrentPlayer, whiteMen, blackMen, kingMove, fullMove;

	getline(SSFEN, newCurrentPlayer, ':');
	getline(SSFEN, whiteMen, ':');
	getline(SSFEN, blackMen, ':');
	getline(SSFEN, kingMove, ':');
	getline(SSFEN, fullMove, ':');

	kingMove.erase(0, 1);
	kingMovesCounter = stoi(kingMove);

	fullMove.erase(0, 1);
	turnCounter = stoi(fullMove);

	whiteMen.erase(0, 1);
	setupMen(whiteMen, true);

	blackMen.erase(0, 1);
	setupMen(blackMen, false);

	return newCurrentPlayer;
}

void Board::setupMen(string MenLayout, bool bWhite)
{
	stringstream allMenIndexes;
	allMenIndexes << MenLayout;
	
	string smenIndex;
	int menIndex;

	if (getline(allMenIndexes, smenIndex, ',')) {
		menIndex = stoi(smenIndex);
	}
	else {
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (GetTile(PositionStruct{ i, j })->index == menIndex) {
				
				GetTile(PositionStruct{ i, j })->men = new Men(bWhite, PositionStruct{ i, j });
				
				if (getline(allMenIndexes, smenIndex, ',')) {
					menIndex = stoi(smenIndex);
				}
				else {
					return;
				}
			}
		}
	}
}

void Board::MoveMen(PositionStruct men, PositionStruct destination)
{
	//Check the direction in which to check via rowIncrement and columnIncrement, and save the current position to check
	int rowIncrement = (men.row - destination.row < 0) ? 1 : -1;
	int columnIncrement = (men.column - destination.column < 0) ? 1 : -1;
	PositionStruct positionToCheck = PositionStruct{ men.row + rowIncrement, men.column + columnIncrement };

	// while we haven't reach the destination, loop through each tile between the selected men and the destination
	while (!(positionToCheck == destination)) {

		// If the tile contain a men, alive and of the opposite color, set his "alive" bool to false
		if (GetTile(positionToCheck)->men != nullptr &&
			GetTile(positionToCheck)->men->GetWhite() != GetTile(men)->men->GetWhite() &&
			GetTile(positionToCheck)->men->GetAlive()) {

			GetTile(positionToCheck)->men->SetAlive(false);
			break;
		}

		positionToCheck.row += rowIncrement;
		positionToCheck.column += columnIncrement;
	}
	
	// Move the men from his current tile to the destination tile
	gameBoard[destination.row][destination.column]->men = gameBoard[men.row][men.column]->men;
	gameBoard[men.row][men.column]->men = nullptr;
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

void Board::UpdateFEN(string playerTurn)
{
	fenHistory.push_back(playerTurn + GetMenLayout() + ":H" + to_string(kingMovesCounter) + GetAndUpdateAmountOfTurn(playerTurn == "B"));
}

string Board::GetMenLayout()
{
	string MenLayout;
	stringstream whiteLayout;
	stringstream blackLayout;
	
	// Loop through each tile to update whiteLayout and blackLayout with the indexes of their Men
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (GetTile(PositionStruct{ i , j })->men != nullptr) {
				if (GetTile(PositionStruct{ i , j })->men->GetWhite()) {
					whiteLayout << GetTile(PositionStruct{ i , j })->index << ",";
				}
				else {
					blackLayout << GetTile(PositionStruct{ i , j })->index << ",";
				}
			}
		}
	}
	
	// Convert the stringstream to string to remove the last comma
	string finalWhiteLayout = whiteLayout.str();
	finalWhiteLayout.pop_back();

	string finalBlackLayout = blackLayout.str();
	finalBlackLayout.pop_back();

	// Put everzthing together and return it
	MenLayout = ":W" + finalWhiteLayout + ":B" + finalBlackLayout;

	return MenLayout;
}

string Board::GetAndUpdateAmountOfTurn(bool blackPlayerTurn)
{
	if (blackPlayerTurn) {
		turnCounter++;
	}

	string TurnCounterFEN = ":F" + to_string(turnCounter);

	return TurnCounterFEN;
}

void Board::DisplayBoard()
{
	for (int i = 0; i < 10; i++) {
		cout << "|";
		for (int j = 0; j < 10; j++) {

			if (gameBoard[i][j]->index != -1) {
				//cout << gameBoard[i][j]->index << "\t|";
				if (GetTile(PositionStruct{ i , j })->men != nullptr && GetTile(PositionStruct{ i , j })->men->GetAlive()) {
					
					if (GetTile(PositionStruct{ i , j })->men->GetWhite()) {
						cout << "w" << "\t|";
					}
					else {
						cout << "b" << "\t|";
					}
				}
				else {
					cout << " e " << "\t|";
				}
			}
			else {
				cout << " \t|";
			}
		}
		cout << endl;
	}
}