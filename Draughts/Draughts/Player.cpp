#include "Player.h"
#include "TileStruct.h"

Player::Player(bool white)
{
	bWhite = white;

	remainingMen.reserve(20);
}

void Player::InitialiseMen()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Board::GetBoardSingleton()->GetTile(i, j)->index != -1 &&
				Board::GetBoardSingleton()->GetTile(i, j)->men != nullptr &&
				Board::GetBoardSingleton()->GetTile(i, j)->men->GetWhite() == bWhite) {

				if (Board::GetBoardSingleton()->GetTile(i, j)->men->GetKing()) {
					remainingKing.push_back(Board::GetBoardSingleton()->GetTile(i, j)->men);
				}
				else {
					remainingMen.push_back(Board::GetBoardSingleton()->GetTile(i, j)->men);
				}
			}
		}
	}
}

bool Player::HaveLegalMoveLeft()
{
	for (Men* men : remainingMen) {
		if (!(men->CanMove().empty())) {
			return true;
		}
	}

	for (Men* men : remainingKing) {
		if (!(men->CanMove().empty())) {
			return true;
		}
	}

	return false;
}

bool Player::StillHaveMen()
{
	if (remainingMen.empty() && remainingKing.empty()) {
		return false;
	}

	return false;
}

PositionStruct* Player::GetHungriestMen(Men* hungryMen)
{
	return nullptr;
}

vector<Men*> Player::GetAllMenWhoCanEat()
{
	vector<Men*> outputMen;

	for (Men* men : remainingMen) {
		
		if (!(men->CanEat().empty())) {
			outputMen.push_back(men);
		}
	}

	if (outputMen.empty()) {
		cout << "There is nothing" << endl;
	}

	return outputMen;
}

void Player::RemoveMen(Men* men)
{
	vector<Men*> menAlive;
	vector<Men*> kingAlive;

	for (Men* men : remainingMen) {
		if (men->GetAlive()) {
			menAlive.push_back(men);
		}
		else {
			delete men;
		}
	}

	remainingMen = menAlive;

	for (Men* men : remainingKing) {
		if (men->GetAlive()) {
			kingAlive.push_back(men);
		}
		else {
			delete men;
		}
	}

	this->remainingKing = kingAlive;
}

bool Player::GetbWhite()
{
	return bWhite;
}

void Player::Test()
{
	for (Men* men : remainingMen) {
		for (PositionStruct pos : men->CanMove()) {
			Board::GetBoardSingleton()->GetTile(pos)->bHighlight = true;
		}
	}

	for (Men* men : remainingKing) {
		for (PositionStruct pos : men->CanMove()) {
			Board::GetBoardSingleton()->GetTile(pos)->bHighlight = true;
		}
	}
}
