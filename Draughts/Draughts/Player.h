#pragma once
#include "Board.h"
#include "Men.h"
#include <vector>
#include "PositionStruct.h"
#include <iostream>

class Player
{

private:

	vector<Men*> remainingMen;
	vector<Men*> remainingKing;
	bool bWhite;

public:

	// Player logic
	Player(bool white);
	void InitialiseMen();
	bool HaveLegalMoveLeft();
	bool StillHaveMen();
	vector<PositionStruct> GetMenWhoCanMove();
	vector<vector<PositionStruct>>* GetHungriestMen(vector<Men*> hungryMen);
	vector<Men*> GetAllMenWhoCanEat();
	void UpdateMen();
	bool OneKingLeft();
	bool HasAtLeastOneKing();

	// Getters and Setters
	bool GetbWhite();
	vector<Men*> GetAllMenAndKing();
};

