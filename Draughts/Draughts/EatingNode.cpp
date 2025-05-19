#include "EatingNode.h"

EatingNode::EatingNode(PositionStruct newData)
{
	next = nullptr;
	data = newData;
}

EatingNode* EatingNode::GetNext()
{
	return next;
}

void EatingNode::SetNext(EatingNode* newNext)
{
	next = newNext;
}

PositionStruct EatingNode::GetData()
{
	return data;
}

void EatingNode::SetData(PositionStruct newData)
{
	data = newData;
}
