#pragma once
#include "PositionStruct.h"
#include "EatingNode.h"

class EatingList
{
private:

	EatingNode* head;
	int lenght;

public:

	EatingList();
	~EatingList();
	void PushNode(PositionStruct* newNode);
	void PopNode();
	PositionStruct* GetData();
	int GetLenght();
	void DisplayList();

};

