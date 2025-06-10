#include "Player.h"
#include "TileStruct.h"

Player::Player(bool white)
{
	bWhite = white;

	remainingMen = nullptr;
	remainingKing = nullptr;
}

void Player::InitialiseMen()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Board::GetBoardSingleton()->GetTile(i, j)->index != -1 &&
				Board::GetBoardSingleton()->GetTile(i, j)->men != nullptr &&
				Board::GetBoardSingleton()->GetTile(i, j)->men->GetWhite() == bWhite) {

				if (Board::GetBoardSingleton()->GetTile(i, j)->men->GetKing()) {
					remainingKing->push_back(Board::GetBoardSingleton()->GetTile(i, j)->men);
				}
				else {
					remainingMen->push_back(Board::GetBoardSingleton()->GetTile(i, j)->men);
				}
			}
		}
	}
}

bool Player::HaveLegalMoveLeft()
{
	return false;
}

bool Player::StillHaveMen()
{
	return false;
}

PositionStruct* Player::GetHungriestMen(Men* hungryMen)
{
	return nullptr;
}

vector<Men*> Player::GetAllMenWhoCanEat()
{
	vector<Men*> outputMen;

	for (Men* men : *remainingMen) {
		
		if (men->CanEat().empty()) {
			cout << "Men at position (" << men->position.row << "," << men->position.column << ") is not hungry";
		}
		else {
			outputMen.push_back(men);
			cout << "Men at position (" << men->position.row << "," << men->position.column << ") is hungry";
		}
	}

	if (outputMen.empty()) {
		cout << "There is nothing" << endl;
	}

	return outputMen;
}

void Player::RemoveMen(Men* men)
{
	vector<Men*>* menAlive = nullptr;
	vector<Men*>* kingAlive = nullptr;

	for (Men* men : *remainingMen) {
		if (men->GetAlive()) {
			menAlive->push_back(men);
		}
		else {
			delete men;
		}
	}

	remainingMen = menAlive;

	for (Men* men : *remainingKing) {
		if (men->GetAlive()) {
			kingAlive->push_back(men);
		}
		else {
			delete men;
		}
	}

	remainingKing = kingAlive;
}

bool Player::GetbWhite()
{
	return bWhite;
}

void Player::Test()
{
	cout << remainingMen->size() << endl;
}