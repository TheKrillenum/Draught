#include "EatingList.h"

EatingList::EatingList(EatingNode* firstNode = nullptr)
{
	head = firstNode;
	
	if (head != nullptr) {
		lenght = 1;
	}
	else {
		lenght = 0;
	}
}

EatingList::~EatingList()
{
	delete head;
}

void EatingList::PushNode(EatingNode* newNode)
{
	newNode->SetNext(head);
	head = newNode;
	lenght++;
}

void EatingList::PopNode()
{
	EatingNode* temp = head->GetNext();
	delete head;
	head = temp;
	lenght--;
}

EatingNode* EatingList::GetNode()
{
	return head;
}
