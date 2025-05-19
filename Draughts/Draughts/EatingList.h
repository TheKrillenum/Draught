#pragma once
#include "EatingNode.h"

class EatingList
{
private:

	EatingNode* head;
	int lenght;

public:

	EatingList(EatingNode* firstNode);
	~EatingList();
	void PushNode(EatingNode* newNode);
	void PopNode();
	EatingNode* GetNode();

};

