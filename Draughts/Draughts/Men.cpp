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

vector<PositionStruct> Men::CanEat()
{
	vector<PositionStruct> eatingPosition;
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
	}

	return eatingPosition;
}

vector<PositionStruct> Men::CanMove()
{
	vector<PositionStruct> output = CanEat();

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
	}

	return output;
}

vector<PositionStruct> Men::LongestEatingRoute(PositionStruct currentPosition)
{
	return vector<PositionStruct>();
}
