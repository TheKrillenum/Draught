#include "GameManager.h"
#include "TileStruct.h"
#include <sstream>

using namespace std;

GameManager::GameManager()
{
	DefaultFEN = "W:W31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50:B1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20:H0:F1";

	Player* white = new Player(true);
	Player* black = new Player(false);

	gameOngoing = true;
	situation = FullArmy;

	allPlayers[0] = white;
	allPlayers[1] = black;

	currentPlayer = white;
}

void GameManager::StartGame()
{
	cout << "Welcome to draught player" << endl << "Do you wish to generate the board using a custom FEN ?";
	cout << endl << "Enter Y for yes or N for no";
	cout << endl << endl;
	cout << "[Answer]>";

	string answer;
	cin >> answer;

	while (answer != "Y" && answer != "N" && answer != "y" && answer != "n") {
		cout << "Wrong input. You have to input Y for yes and N for no, try again." << endl << endl;
		cout << "[Answer]>";

		cin >> answer;
	}

	if (answer == "Y" || answer == "y") {
		cout << "Please enter your custom FEN (it must be valid)" << endl << endl;
		cout << "[Custom FEN]>";
		string FEN;
		cin >> FEN;
		Board::GetBoardSingleton()->LoadBoard(FEN);
		Board::GetBoardSingleton()->GetFenHistory()->push_back(FEN);
	}

	else {
		Board::GetBoardSingleton()->LoadBoard(DefaultFEN);
		Board::GetBoardSingleton()->GetFenHistory()->push_back(DefaultFEN);
	}
}

void GameManager::PlayGame()
{
	
	StartGame();	// Load default FEN or a custom given FEN

	Board::GetBoardSingleton()->DisplayBoard();

	
	for (Player* player : allPlayers) {
		player->InitialiseMen();
	}

	/*
	* 
	CheckAmountOfKingMoves();

	while (gameOngoing)
	{
		PlayTurn();

		string startingPlayer = (currentPlayer->GetbWhite()) ? "W" : "B";
		Board::GetBoardSingleton()->UpdateFEN(startingPlayer);

		if (CheckGameIsWon()) {
			EndGame(currentPlayer);
			break;
		}

		if (CheckGameIsDraw()) {
			DrawGame();
			break;
		}

		SwitchCurrentPlayer();
	}
	*/
}

void GameManager::PlayTurn()
{

	vector<Men*> hungryMen;
	vector<vector<PositionStruct>>* longestEatingPaths = nullptr;
	bool pathAvailable = false;
	vector<PositionStruct> menToChooseFrom;

	hungryMen = currentPlayer->GetAllMenWhoCanEat();

	if (!hungryMen.empty()) {

		longestEatingPaths = currentPlayer->GetHungriestMen(hungryMen);

		for (vector<PositionStruct> individualPath : *longestEatingPaths) {
			
			menToChooseFrom.push_back(individualPath.front());

		}
	}


	PositionStruct chosenMen;
	PositionStruct chosenDestination;
	bool confirmChosenMen = true;

	while (confirmChosenMen) {

		chosenMen = PlayerReturnChosenMen(menToChooseFrom);

		chosenDestination = PlayerReturnChosenDestination(chosenMen, menToChooseFrom);

		if (chosenDestination == PositionStruct{ -1 , -1 }) {
			confirmChosenMen = true;
		}
		else {
			confirmChosenMen = false;
		}
	}
	
	switch (situation) {
	case FullArmy:
		Board::GetBoardSingleton()->MoveMen(chosenMen, chosenDestination, false);
		break;
	case ThreeMen:
	case LessThreeMen:
		Board::GetBoardSingleton()->MoveMen(chosenMen, chosenDestination, true);
		break;
	}

	if (longestEatingPaths != nullptr) {

		while (!longestEatingPaths->empty()) {

			longestEatingPaths->erase(longestEatingPaths->begin());

			for (vector<PositionStruct> individualPath : *longestEatingPaths) {

				menToChooseFrom.push_back(individualPath.front());

			}

			chosenDestination = PlayerReturnChosenDestination(chosenMen, menToChooseFrom);

			switch (situation) {
			case FullArmy:
				Board::GetBoardSingleton()->MoveMen(chosenMen, chosenDestination, false);
				break;
			case ThreeMen:
			case LessThreeMen:
				Board::GetBoardSingleton()->MoveMen(chosenMen, chosenDestination, true);
				break;
			}
		}

	}

	Board::GetBoardSingleton()->CheckMenBecomeKing(chosenMen);

	Player* oppositePlayer = (currentPlayer == allPlayers[0]) ? allPlayers[1] : allPlayers[0];

	oppositePlayer->RemoveMen();
}

PositionStruct GameManager::PlayerReturnChosenMen(const vector<PositionStruct>& menToChoose)
{
	PositionStruct chosenMen;
	bool validChoice = false;

	while (!validChoice) {

		while (getValidPlayerInput(chosenMen));

		if (!menToChoose.empty()) {

			for (PositionStruct pos : menToChoose) {
				if (pos == chosenMen) {
					validChoice = true;
				}
			}

		}
		else {
			validChoice = true;
		}
	}

	return chosenMen;
}

PositionStruct GameManager::PlayerReturnChosenDestination(PositionStruct chosenMen, vector<PositionStruct> availableMen)
{

	if (Board::GetBoardSingleton()->GetTile(chosenMen)->men == nullptr) {
		return PositionStruct{ -1 , -1 };
	}

	vector <PositionStruct> destinationChoice;

	destinationChoice = Board::GetBoardSingleton()->GetTile(chosenMen)->men->CanMove();

	if (destinationChoice.empty()) {
		return PositionStruct{ -1 , -1 };
	}

	PositionStruct playerChoice;
	

	



	return playerChoice;
}

bool GameManager::CheckGameIsWon()
{
	Player* playerToCheck = (currentPlayer == allPlayers[0]) ? allPlayers[1] : allPlayers[0];

	if (!(playerToCheck->StillHaveMen())) {
		return true;
	}

	if (!playerToCheck->HaveLegalMoveLeft()) {
		return true;
	}

	return false;
}

bool GameManager::CheckGameIsDraw()
{
	for (Player * player : allPlayers)
	{
		if (CheckAmountOfKingMoves()) {
			return true;
		}
	}

	if (CheckRepetitionFEN()) {
		return true;
	}

	return false;
}

bool GameManager::CheckAmountOfKingMoves()
{
	if (allPlayers[0]->OneKingLeft() || allPlayers[1]->OneKingLeft()) {

		if (allPlayers[0]->OneKingLeft() && allPlayers[1]->OneKingLeft()) {
			situation = LessThreeMen;
		}
		else {

			Player* playerWithMoreThenOneKing = (allPlayers[0]->OneKingLeft()) ? allPlayers[1] : allPlayers[0];

			if (playerWithMoreThenOneKing->HasAtLeastOneKing()) {

				if (playerWithMoreThenOneKing->GetAllMenAndKing().size() == 3) {
					situation = ThreeMen;
				}
				else if (playerWithMoreThenOneKing->GetAllMenAndKing().size() < 3) {
					situation = LessThreeMen;
				}
				else {
					situation = FullArmy;
				}
			}
			else {
				situation = FullArmy;
			}
		}
	}

	int kingMoves = Board::GetBoardSingleton()->GetKingMoveCounter();

	switch (situation) {
	case FullArmy:
		if (kingMoves >= 50) {
			return true;
		}
		break;
	case ThreeMen:
		if (kingMoves >= 36) {
			return true;
		}
		break;
	case LessThreeMen:
		if (kingMoves >= 10) {
			return true;
		}
		break;
	}

	return false;
}

bool GameManager::CheckRepetitionFEN()
{
	vector<string>* allFen = Board::GetBoardSingleton()->GetFenHistory();

	for (string fenToCheck : *allFen) {

		int repetition = 0;

		stringstream  relevantStreamFenToCheck;
		string relevantStringFenToCheck;
		relevantStreamFenToCheck << fenToCheck;

		getline(relevantStreamFenToCheck, relevantStringFenToCheck, 'H');

		for (string fen : *allFen) {

			stringstream  relevantStreamFen;
			string relevantStringFen;
			relevantStreamFen << fen;

			getline(relevantStreamFen, relevantStringFen, 'H');

			if (relevantStringFen == relevantStringFenToCheck) {
				repetition++;
			}
		}

		if (repetition >= 3) {

			return true;
		}
	}

	return false;
}

void GameManager::SwitchCurrentPlayer()
{
	currentPlayer = (currentPlayer == allPlayers[0]) ? allPlayers[1] : allPlayers[0];
}

void GameManager::DrawGame()
{
	cout << "Game is a draw ! There is no winner.";

	gameOngoing = false;
}

void GameManager::EndGame(Player winner)
{
	cout << "Game is over !" << endl << "The winner is: ";

	if (winner.GetbWhite()) {
		cout << "white player.";
	}
	else {
		cout << "black player.";
	}

	gameOngoing = false;
}

void GameManager::removeWhiteSpace(string& inputLine) {
	int count = 0;
	int i = 0;

	while (inputLine[i++] == ' ') count++;

	inputLine.erase(0, count);

	i = inputLine.length() - 1;
	count = 0;

	while (inputLine[i--] == ' ') count++;

	inputLine.erase(inputLine.length() - count, count);


}

bool GameManager::getValidPlayerInput(PositionStruct& position) {

	Board::GetBoardSingleton()->DisplayBoard();

	cout << "Please choose the position of a Men to be moved by entering" << endl;
	cout << "it's position in the form 'row column', seperate by a white space" << endl;
	cout << "[ChosenMen'sPosition]>";

	string inputLine;
	do {
		getline(cin, inputLine);
	} while (inputLine == "");

	removeWhiteSpace(inputLine);

	stringstream inputStream(inputLine);

	bool fail1 = (inputStream >> position.row).fail();
	bool fail2 = (inputStream >> position.column).fail();
	bool fail3 = inputStream.peek() != EOF;

	return !fail1 && !fail2 && !fail3 && !Board::GetBoardSingleton()->ValidPosition(position);
}