#pragma once
#include "Board.h"
#include "Men.h"
#include <vector>
#include "PositionStruct.h"
#include <iostream>

class Player
{

private:

	vector<Men*>* remainingMen;
	vector<Men*>* remainingKing;
	bool bWhite;

public:

	// Player logic
	Player(bool white);
	void InitialiseMen();
	bool HaveLegalMoveLeft();
	bool StillHaveMen();
	PositionStruct* GetHungriestMen(Men* hungryMen);
	vector<Men*> GetAllMenWhoCanEat();
	void RemoveMen(Men* men);

	// Getters and Setters
	bool GetbWhite();

	void Test();
};

