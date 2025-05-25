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

    Board::GetBoardSingleton()->DisplayBoard();
    Board::GetBoardSingleton();

    return 0;
}