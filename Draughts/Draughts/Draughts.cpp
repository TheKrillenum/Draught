#include <iostream>
#include "TileStruct.h"
#include "PositionStruct.h"
#include "GameManager.h"
#include "Board.h"

using namespace std;

int main()
{
    GameManager gm;

    gm.PlayGame();
    //Board::GetBoardSingleton()->DisplayBoard();
    //Board::GetBoardSingleton()->VisualTest();

    return 0;
}

// W:W31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50:B1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20:H0:F1
// W:W26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50:B1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25:H0:F1
// W:W31,32,33,34,35,36,K37,38,39,40,41,42,43,K44,45,46,47,48,49,50:BK1,2,3,4,5,6,7,8,9,K10,11,12,13,14,K15,16,17,18,19,20,27,28:H0:F1
// W:WK22:B9,11,13,17,27,39:H0:F1
// W:W1,K22:B7,39:H0:F1
// W:W48:B12,21,22,33,43,44:H0:F1
// W:W5,48:B10,12,20,21,22,33,43,44:H0:F1
// W:W48,K50:B2,K3,5:H