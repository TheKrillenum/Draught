#pragma once
#include "PositionStruct.h"
#include "DynamicArray.h"
#include "Men.h"

class Player
{

private:

	Men* remainingMen[20];
	Men* remainingKing[20];
	bool bWhite;

public:

	Player(bool white);
	bool HaveLegalMoveLeft();
	bool StillHaveMen();
	PositionStruct* GetHungriestMen(Men* hungryMen);
	Men* GetAllMenWhoCanEat();
	void RemoveMen(Men* men);

	bool GetbWhite();
};

