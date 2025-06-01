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

bool Men::GetAlive()
{
	return bAlive;
}

void Men::SetAlive(bool isAlive)
{
	bAlive = isAlive;
}

void Men::TransformToKing()
{
	bKing = true;
}

vector<PositionStruct>* Men::CanEat()
{
	return nullptr;
}
