#include <iostream>
#include "EatingList.h"


using namespace std;

EatingList::EatingList()
{
	head = nullptr;
	lenght = 0;
}

EatingList::~EatingList()
{
	delete head;
}

void EatingList::PushNode(PositionStruct* newNode)
{
	EatingNode* temp = new EatingNode(newNode);
	temp->SetNext(head);
	head = temp;

	lenght++;
}

void EatingList::PopNode()
{
	if (head == nullptr) {
		return;
	}

	EatingNode* temp = head->GetNext();
	delete head;
	head = temp;
	lenght--;
}

PositionStruct* EatingList::GetData()
{
	if (head != nullptr) {
		return head->GetData();
	}
	else {
		PositionStruct* temp = new PositionStruct{ -1 , -1 };
		return temp;
	}
}

int EatingList::GetLenght()
{
	return lenght;
}

void EatingList::DisplayList()
{
	cout << "Displaying list of lenght " << lenght << endl;

	EatingNode* temp = head;

	while (temp != nullptr) {
		cout << "-> row:" << temp->GetData()->row << " column:" << temp->GetData()->column << endl;
		temp = temp->GetNext();
	}

	cout << "----------------------------";
	cout << endl << endl;
}
