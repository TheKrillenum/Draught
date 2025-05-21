#pragma once
#include "PositionStruct.h"
#include "DynamicArray.h"

class Men
{

private:

	bool bAlive;
	bool bKing;
	bool bWhite;
	PositionStruct position;

public:

	Men(bool white, PositionStruct initPosition);
	PositionStruct* CanEat();
	PositionStruct* CanMove();
	PositionStruct* LongestEatingRoute(PositionStruct currentPosition);

};

