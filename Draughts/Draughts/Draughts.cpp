#include <iostream>
#include "TileStruct.h"
#include "PositionStruct.h"
#include "GameManager.h"
#include "Board.h"

using namespace std;

int main()
{
    GameManager gm;
    cout << "Test initiated";
    cout << endl;

    gm.PlayGame();
    Board::GetBoardSingleton()->DisplayBoard();
    //Board::GetBoardSingleton()->VisualTest();
    cout << endl << endl;

    return 0;
}

// W:W31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50:B1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20:H0:F1
// W:W31,32,33,34,35,36,K37,38,39,40,41,42,43,K44,45,46,47,48,49,50:BK1,2,3,4,5,6,7,8,9,K10,11,12,13,14,K15,16,17,18,19,20,27,28:H0:F1
// W:WK22:B9,11,13,17,27,39:H0:F1