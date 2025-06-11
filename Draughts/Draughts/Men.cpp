#include "Men.h"
#include "TileStruct.h"
#include <iostream>

Men::Men(bool white, PositionStruct initPosition, bool king)
{
	bWhite = white;
	bKing = king;
	position = initPosition;

	bAlive = true;
}

bool Men::GetWhite()
{
	return bWhite;
}

bool Men::GetKing()
{
	return bKing;
}

bool Men::GetAlive()
{
	return bAlive;
}

void Men::SetAlive(bool isAlive)
{
	bAlive = isAlive;
}

void Men::TransformToKing()
{
	bKing = true;
}

void Men::AppendPositionVector(vector<PositionStruct>* mainVector, vector<PositionStruct> insertVector)
{
	mainVector->insert(mainVector->end(), insertVector.begin(), insertVector.end());
}

vector<PositionStruct> Men::CanEat()
{
	vector<PositionStruct> eatingPosition;
	/*
	* 
	* DEPRECATED
	* 
	PositionStruct emptyPosition;
	PositionStruct positionToEat;

	for (int i = -1; i < 2; i += 2) {
		for (int j = -1; j < 2; j += 2) {

			bool bAvailableTiles = true;
			int increment = 1;

			while (bAvailableTiles) {

				positionToEat = PositionStruct{ position.row + (i * increment), position.column + (j * increment) };
				emptyPosition = PositionStruct{ position.row + (i * (increment + 1)), position.column + (j * (increment + 1)) };

				if (Board::GetBoardSingleton()->ValidPosition(emptyPosition)) {

					if (Board::GetBoardSingleton()->GetTile(positionToEat)->men != nullptr &&
						Board::GetBoardSingleton()->GetTile(positionToEat)->men->GetAlive() == true &&
						Board::GetBoardSingleton()->GetTile(positionToEat)->men->GetWhite() != bWhite) {

						if (Board::GetBoardSingleton()->GetTile(emptyPosition)->men == nullptr) {

							// Can be eaten, add it
							eatingPosition.push_back(PositionStruct{ position.row + (i * (increment + 1)), position.column + (j * (increment + 1)) });
							bAvailableTiles = false;
						}
						else {

							// Cannot be eaten and block us, stop checking
							bAvailableTiles = false;

						}

					}
					else if (Board::GetBoardSingleton()->GetTile(positionToEat)->men == nullptr) {
						//Keep checking
						bAvailableTiles = true;
						increment++;
					}
					else {
						// Ally block us, or isn't alive and still block us
						bAvailableTiles = false;
					}
				}
				else {
					bAvailableTiles = false;
				}

				if (!bKing) {
					break;
				}

			}
		}
	}*/

	AppendPositionVector(&eatingPosition, CheckDirection(TopRight, position, bWhite, bKing, true));
	AppendPositionVector(&eatingPosition, CheckDirection(TopLeft, position, bWhite, bKing, true));
	AppendPositionVector(&eatingPosition, CheckDirection(BottomRight, position, bWhite, bKing, true));
	AppendPositionVector(&eatingPosition, CheckDirection(BottomLeft, position, bWhite, bKing, true));

	return eatingPosition;
}

vector<PositionStruct> Men::CanMove()
{
	vector<PositionStruct> output;

	/*
	* 
	*	DEPRECATED
	* 
	int CheckDirection = (bWhite) ? -1 : 1;

	PositionStruct rightTile;
	PositionStruct leftTile;
	int increment = 1;
	bool bTilesAvailable = true;

	// these represent forward-right (fr), forward-left (fl), backward-right (br) and backward-left (bl). They are meant to keep 
	// track of any blockus in a direction: if this Men is blocked from continuing in a direction, further tiles in that same
	// direction won't be checked.
	bool fr = true;
	bool fl = true;
	bool br = true;
	bool bl = true;

	while(bTilesAvailable){
		
		bTilesAvailable = false;

		rightTile = PositionStruct{ position.row + (CheckDirection * increment), position.column + increment };
		leftTile = PositionStruct{ position.row + (CheckDirection * increment), position.column - increment };

		if (Board::GetBoardSingleton()->ValidPosition(rightTile) &&
			Board::GetBoardSingleton()->GetTile(rightTile)->men == nullptr &&
			fr) {
			
			output.push_back(rightTile);
			bTilesAvailable = true;
		}
		else {
			fr = false;
		}

		if (Board::GetBoardSingleton()->ValidPosition(leftTile) &&
			Board::GetBoardSingleton()->GetTile(leftTile)->men == nullptr &&
			fl) {
			
			output.push_back(leftTile);
			bTilesAvailable = true;
		}
		else {
			fl = false;
		}

		if (!bKing) {
			break;
		}

		rightTile = PositionStruct{ position.row + (CheckDirection * increment *-1), position.column + increment };
		leftTile = PositionStruct{ position.row + (CheckDirection * increment *-1), position.column - increment };

		if (Board::GetBoardSingleton()->ValidPosition(rightTile) &&
			Board::GetBoardSingleton()->GetTile(rightTile)->men == nullptr &&
			br) {

			output.push_back(rightTile);
			bTilesAvailable = true;
		}
		else {
			br = false;
		}

		if (Board::GetBoardSingleton()->ValidPosition(leftTile) &&
			Board::GetBoardSingleton()->GetTile(leftTile)->men == nullptr &&
			bl) {

			output.push_back(leftTile);
			bTilesAvailable = true;
		}
		else {
			bl = false;
		}

		increment++;
	}*/

	AppendPositionVector(&output, CheckDirection(TopRight, position, bWhite, bKing, false));
	AppendPositionVector(&output, CheckDirection(TopLeft, position, bWhite, bKing, false));
	AppendPositionVector(&output, CheckDirection(BottomRight, position, bWhite, bKing, false));
	AppendPositionVector(&output, CheckDirection(BottomLeft, position, bWhite, bKing, false));

	return output;
}

void Men::LongestEatingRoute(vector<vector<PositionStruct>>* eatingPath, vector<PositionStruct> currentPath, PositionStruct currentPosition)
{
	Direction dir;
	PositionStruct enemyPosition;

	for (int i = 0; i < 4; i++) {

		switch (i) {
		case 0:
			dir = TopRight;
			break;
		case 1:
			dir = TopLeft;
			break;
		case 2:
			dir = BottomRight;
			break;
		case 3:
			dir = BottomLeft;
			break;
		default:
			break;
		}

		vector<PositionStruct> destination = CheckDirection(dir, currentPosition, bWhite, bKing, true);

		if (!destination.empty()) {

			PositionStruct debug = destination.front();
			enemyPosition.row = ((destination.front().row - currentPosition.row) > 0) ? destination.front().row - 1 : destination.front().row + 1;
			enemyPosition.column = ((destination.front().column - currentPosition.column) > 0) ? destination.front().column - 1 : destination.front().column + 1;

			Board::GetBoardSingleton()->GetTile(enemyPosition)->men->SetAlive(false);

			currentPath.push_back(destination.front());

			LongestEatingRoute(eatingPath, currentPath, destination.front());

			Board::GetBoardSingleton()->GetTile(enemyPosition)->men->SetAlive(true);
		}
		else {
			
			if (!eatingPath->empty()) {

				if (eatingPath->front().size() == currentPath.size()) {

					eatingPath->push_back(currentPath);

				}
				else if (eatingPath->front().size() < currentPath.size()) {
					eatingPath->clear();
					eatingPath->push_back(currentPath);
				}
			}
			else {
				eatingPath->push_back(currentPath);
			}
		}
	}

	return;
}

vector<PositionStruct> Men::CheckDirection(Direction dir, PositionStruct currentPosition, bool white, bool king, bool eat)
{
	vector<PositionStruct> output;
	int forward, sideways, increment;
	bool bTileAvailable = true;
	PositionStruct tileToCheck;
	increment = 1;

	switch (dir) {
	case 0:
		forward = -1;
		sideways = 1;
		break;
	case 1:
		forward = -1;
		sideways = -1;
		break;
	case 2:
		forward = 1;
		sideways = 1;
		break;
	case 3:
		forward = 1;
		sideways = -1;
		break;
	default :
		break;
	}

	while (bTileAvailable) {

		bTileAvailable = false;

		tileToCheck = PositionStruct{ currentPosition.row + (increment * forward), currentPosition.column + (increment * sideways) };

		if (Board::GetBoardSingleton()->ValidPosition(tileToCheck)) {

			if (Board::GetBoardSingleton()->GetTile(tileToCheck)->men == nullptr) {

				bTileAvailable = true;

				if (!eat) {
					output.push_back(tileToCheck);
				}

			}
			else if(Board::GetBoardSingleton()->GetTile(tileToCheck)->men->bAlive &&
					Board::GetBoardSingleton()->GetTile(tileToCheck)->men->bWhite != white &&
					Board::GetBoardSingleton()->ValidPosition(PositionStruct{ tileToCheck.row + forward, tileToCheck.column + sideways }) &&
					Board::GetBoardSingleton()->GetTile(tileToCheck.row + forward, tileToCheck.column + sideways)->men == nullptr){

					output.push_back(PositionStruct{ tileToCheck.row + forward, tileToCheck.column + sideways });
			}
		}

		if (!king) {
			break;
		}
		else {
			increment++;
		}
	}

	return output;
}

PositionStruct Men::GetPosition()
{
	return position;
}
