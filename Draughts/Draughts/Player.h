#pragma once
#include "PositionStruct.h"
#include "Board.h"
#include "Men.h"
#include <vector>

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
	vector<Men*>* GetAllMenWhoCanEat();
	void RemoveMen(Men* men);

	bool GetbWhite();
};

