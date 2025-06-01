#include <iostream>
#include "TileStruct.h"
#include "PositionStruct.h"
#include "DynamicArray.h"
#include "EatingList.h"
#include "EatingNode.h"
#include "GameManager.h"
#include "Board.h"

using namespace std;

int main()
{
    cout << "Test initiated";
    cout << endl;

    Board::GetBoardSingleton()->Test();
    Board::GetBoardSingleton()->DisplayBoard();
    cout << " --------------------------------------------------------------- " << endl;
    cout << Board::GetBoardSingleton()->UpdateFEN("W", true);

    return 0;
}