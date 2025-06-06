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
    GameManager gm;
    cout << "Test initiated";
    cout << endl;

    gm.StartGame();
    Board::GetBoardSingleton()->DisplayBoard();
    

    return 0;
}

// W:W31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50:B1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20:H0:F1
// W:W31,32,33,34,35,36,37,38,39,40,41,42,43,44,45:B6,7,8,9,10,11,12,13,14,15,16,17,18,19,20:H0:F1