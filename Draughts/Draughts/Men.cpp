#include "Men.h"
#include "TileStruct.h"
#include <iostream>

Men::Men(bool white, PositionStruct initPosition)
{
	bWhite = white;
	position = initPosition;

	bAlive = true;
	bKing = false;
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

			emptyPosition = PositionStruct{ position.row + (i * 2), position.column + (j * 2) };
			positionToEat = PositionStruct{ position.row + i, position.column + j };
			
			if (Board::GetBoardSingleton()->GetTile(emptyPosition)->men == nullptr &&
				Board::GetBoardSingleton()->GetTile(positionToEat)->men != nullptr &&
				Board::GetBoardSingleton()->GetTile(positionToEat)->men->GetAlive() == true &&
				Board::GetBoardSingleton()->GetTile(positionToEat)->men->GetWhite() != bWhite) {
				
				eatingPosition.push_back(PositionStruct{ position.row + (i * 2), position.column + (j * 2) });
			}
		}
	}

	return eatingPosition;
}
