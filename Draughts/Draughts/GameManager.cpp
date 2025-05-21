#include <iostream>
#include "GameManager.h"
#include "Board.h"

using namespace std;

GameManager::GameManager()
{

	Player* white = new Player(true);
	Player* black = new Player(false);

	allPlayers[0] = white;
	allPlayers[1] = black;

	currentPlayer = white;
}

void GameManager::PlayGame()
{
	// debug mode

	// Load FEN

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
	/*
	Player* temp;
	
	if (!currentPlayer->StillHaveMen()) {
		return true;
	}

	if (!currentPlayer->HaveLegalMoveLeft()) {
		return true;
	}
	*/
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
