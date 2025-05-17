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

	PositionStruct* CanEat();
	PositionStruct* CanMove();
	PositionStruct* LongestEatingRoute(PositionStruct currentPosition);

};

