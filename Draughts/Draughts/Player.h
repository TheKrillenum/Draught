#pragma once
#include "PositionStruct.h"
#include "DynamicArray.h"
#include "Men.h"

class Player
{

private:

	Men* remainingMen;
	Men* remainingKing;
	bool bWhite;

public:

	bool HaveLegalMoveLeft();
	bool StillHaveMen();
	PositionStruct* GetHungriestMen(Men* hungryMen);
	Men* GetAllMenWhoCanEat();
	void RemoveMen(Men* men);

};

