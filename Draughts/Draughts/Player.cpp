#include "Player.h"

Player::Player(bool white)
{
	bWhite = white;
	
	int positionOffset = 0;
	if (!white) {
		positionOffset = 30;
	}

	for (int i = 0; i < 20; i++) {
		remainingKing[i] = nullptr;
		remainingMen[i] = new Men(white, PositionStruct{ 1 , 1 });	// set Men position correctly !
	}
}

bool Player::GetbWhite()
{
	return bWhite;
}
