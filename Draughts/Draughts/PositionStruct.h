#pragma once

struct PositionStruct
{
	int row = 0;
	int column = 0;

bool operator==(const PositionStruct& compared) const {
	if (row != compared.row) {
		return false;
	}

	if (column != compared.column) {
		return false;
	}

	return true;
}

};
