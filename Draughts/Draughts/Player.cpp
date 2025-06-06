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

vector<Men*>* Player::GetAllMenWhoCanEat()
{
	vector<Men*>* outputMen = nullptr;

	for (Men* men : remainingMen) {
		if (men->GetAlive() == false) {
			for (int i = -1; i < 2; i += 2) {
				for (int j = -1; j < 2; j += 2) {
					if (Board::GetBoardSingleton()->GetTile(i, j)->men == nullptr &&
						Board::GetBoardSingleton()->GetTile(i + 1, j + 1)->men != nullptr &&
						Board::GetBoardSingleton()->GetTile(i + 1, j + 1)->men->GetAlive() == true &&
						Board::GetBoardSingleton()->GetTile(i + 1, j + 1)->men->GetWhite() != bWhite) {
						outputMen->push_back(men);
					}
				}
			}
		}
	}
	if (outputMen->empty()) {

		return nullptr;
	}
	else {
		return outputMen;
	}
}

bool Player::GetbWhite()
{
	return bWhite;
}
