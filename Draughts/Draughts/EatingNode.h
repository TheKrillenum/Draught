#pragma once
#include "PositionStruct.h"

class EatingNode
{
private:

	EatingNode* next;
	PositionStruct data;

public:

	EatingNode(PositionStruct newData);
	EatingNode* GetNext();
	void SetNext(EatingNode* newNext);
	PositionStruct GetData();
	void SetData(PositionStruct newData);

};

