#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
	DefaultFEN = "W:W31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50:B1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20:H0:F1";

	Player* white = new Player(true);
	Player* black = new Player(false);

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
	}
	else {
		Board::GetBoardSingleton()->LoadBoard(DefaultFEN);
	}
}

void GameManager::PlayGame()
{
	// debug mode
	
	StartGame();	// Load default FEN or a custom given FEN

	for (Player* player : allPlayers) {
		player->InitialiseMen();
	}

	allPlayers[0]->Test();

	/*
	string playerTurn = "W";

	while (true)
	{
		PlayTurn();

		Board::GetBoardSingleton()->UpdateFEN("W");

		if (CheckGameIsWon()) {
			EndGame(currentPlayer);
		}

		if (CheckGameIsDraw()) {
			DrawGame();
		}

		SwitchCurrentPlayer();
	}
	*/
}

void GameManager::PlayTurn()
{
}

PositionStruct GameManager::PlayerReturnChosenMen(PositionStruct* menToChoose)
{
	return PositionStruct();
}

PositionStruct GameManager::PlayerReturnChosenDestination(PositionStruct chosenMen)
{
	return PositionStruct();
}

bool GameManager::CheckGameIsWon()
{
	Player* playerToCheck = (currentPlayer == allPlayers[0]) ? allPlayers[1] : allPlayers[0];

	if (!playerToCheck->StillHaveMen()) {
		return true;
	}

	if (!playerToCheck->HaveLegalMoveLeft()) {
		return true;
	}

	return false;
}

bool GameManager::CheckGameIsDraw()
{
	/*
	for (Player * player : allPlayers)
	{
		CheckAmountOfKingMoves();
	}
	*/

	if (CheckRepetitionFEN()) {
		return true;
	}

	return false;
}

bool GameManager::CheckAmountOfKingMoves()
{
	return false;
}

bool GameManager::CheckRepetitionFEN()
{
	return false;
}

void GameManager::SwitchCurrentPlayer()
{
	currentPlayer = (currentPlayer == allPlayers[0]) ? allPlayers[1] : allPlayers[0];
}

void GameManager::DrawGame()
{
	cout << "Game is a draw ! There is no winner.";
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
}

void GameManager::GetCurrentPlayer()
{
	if (currentPlayer->GetbWhite()) {
		cout << "white player." << endl;
	}
	else {
		cout << "black player." << endl;
	}
}
