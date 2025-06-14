#pragma once
#include "Board.h"
#include <vector>
#include "PositionStruct.h"

using namespace std;

enum Direction {
	TopRight,
	TopLeft,
	BottomRight,
	BottomLeft
};

class Men
{

private:

	bool bAlive;
	bool bKing;
	bool bWhite;
	PositionStruct position;

public:
	
	Men(bool white, PositionStruct initPosition, bool king);
	bool GetWhite();
	bool GetKing();
	bool GetAlive();
	void SetAlive(bool isAlive);
	void TransformToKing();
	void AppendPositionVector(vector<PositionStruct>* mainVector, vector<PositionStruct> insertVector);
	vector<PositionStruct> CanEat();
	vector<PositionStruct> CanMove();
	void LongestEatingRoute(vector<vector<PositionStruct>>* eatingPath, vector<PositionStruct> currentPath, PositionStruct currentPosition);
	vector<PositionStruct> CheckDirection(Direction dir, PositionStruct currentPosition, bool white, bool king, bool eat);

	PositionStruct GetPosition();
	void SetPosition(PositionStruct newPosition);
};