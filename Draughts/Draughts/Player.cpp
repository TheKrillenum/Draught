#include "Player.h"
#include "TileStruct.h"

Player::Player(bool white)
{
	bWhite = white;
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
	bool legalMoveLeft = false;

	for (Men* men : GetAllMenAndKing()) {
		if (!(men->CanMove().empty())) {
			legalMoveLeft = true;
			break;
		}
	}

	return legalMoveLeft;
}

bool Player::StillHaveMen()
{
	if (GetAllMenAndKing().empty()) {
		return false;
	}

	return true;
}

vector<PositionStruct> Player::GetMenWhoCanMove()
{
	vector<PositionStruct> output;

	for (Men* men : GetAllMenAndKing()) {
		if (!(men->CanMove().empty())) {
			output.push_back(men->GetPosition());
		}
	}

	return output;
}

vector<vector<PositionStruct>>* Player::GetHungriestMen(vector<Men*> hungryMen)
{
	vector<vector<PositionStruct>>* output = new vector<vector<PositionStruct>>();
	vector<vector<PositionStruct>> path;
	int greatestSize = 0;

	for (Men* men : hungryMen) {
		vector<PositionStruct> temp;
		temp.push_back(men->GetPosition());
		men->LongestEatingRoute(&path, temp, men->GetPosition());

		if (!path.empty()) {

			if (path.front().size() > greatestSize) {
				greatestSize = path.front().size();

				if (!output->empty()) {
					output->clear();
				}

				for (vector<PositionStruct> p : path) {
					output->push_back(p);
				}

			}
			else if (path.front().size() == greatestSize) {
				for (vector<PositionStruct> p : path) {
					output->push_back(p);
				}
			}

		}

		path.clear();
	}

	return output;
}

vector<Men*> Player::GetAllMenWhoCanEat()
{
	vector<Men*> outputMen;

	for (Men* men : GetAllMenAndKing()) {
		
		if (!(men->CanEat().empty())) {
			outputMen.push_back(men);
		}
	}

	return outputMen;
}

void Player::UpdateMen()
{
	vector<Men*> menAlive;
	vector<Men*> kingAlive;

	for (Men* men : remainingMen) {
		if (men->GetAlive()) {
			if (men->GetKing()) {
				kingAlive.push_back(men);
			}
			else {
				menAlive.push_back(men);
			}
		}
		else {
			Board::GetBoardSingleton()->GetTile(men->GetPosition())->men = nullptr;
			delete men;
		}
	}

	remainingMen = menAlive;

	for (Men* men : remainingKing) {
		if (men->GetAlive()) {
			kingAlive.push_back(men);
		}
		else {
			Board::GetBoardSingleton()->GetTile(men->GetPosition())->men = nullptr;
			delete men;
		}
	}

	remainingKing = kingAlive;
}

bool Player::OneKingLeft()
{
	if (remainingKing.size() == GetAllMenAndKing().size() == 1) {
		return true;
	}

	return false;
}

bool Player::HasAtLeastOneKing()
{
	if (remainingKing.empty()) {
		return false;
	}

	return true;
}

bool Player::GetbWhite()
{
	return bWhite;
}

vector<Men*> Player::GetAllMenAndKing()
{
	vector<Men*> output;
	output = remainingMen;
	output.insert(output.end(), remainingKing.begin(), remainingKing.end());

	return output;
}
