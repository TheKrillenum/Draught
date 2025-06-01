#pragma once
#include "PositionStruct.h"
#include "DynamicArray.h"
#include <vector>

using namespace std;

class Men
{

private:

	bool bAlive;
	bool bKing;
	bool bWhite;
	PositionStruct position;

public:

	Men(bool white, PositionStruct initPosition);
	bool GetWhite();
	bool GetKing();
	bool GetAlive();
	void SetAlive(bool isAlive);
	void TransformToKing();
	vector<PositionStruct>* CanEat();
	vector<PositionStruct>* CanMove();
	vector<PositionStruct>* LongestEatingRoute(PositionStruct currentPosition);
};

