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

    return 0;
}

// black player = 12
// white player = 9
// hightlight = 14

// W:W31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50:B1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20:H0:F1
