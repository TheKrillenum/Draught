#include "Men.h"

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

void Men::TransformToKing()
{
	bKing = true;
}

vector<PositionStruct>* Men::CanEat()
{
	return nullptr;
}
