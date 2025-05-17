#pragma once
#include "Men.h"

struct TileStruct
{
	int index;
	Men* men;
	bool moveTL;
	bool moveTR;
	bool moveBL;
	bool moveBR;
};