#include <iostream>
#include "TileStruct.h"
#include "PositionStruct.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray<PositionStruct> DA;
    cout << "Current size : " << DA.GetCurrentSize() << "\nCurrent capacity : " << DA.GetCapacity();
    PositionStruct a{ 1 , 1 };
    PositionStruct b{ 2 , 2 };
    PositionStruct c{ 3 , 3 };
    DA.Add(a);
    DA.Add(b);
    cout << "\nNew current size :" << DA.GetCurrentSize() << "\nNew current capacity : " << DA.GetCapacity();
    cout << "\n Array contain :";
    for (int i = 0; i < DA.GetCurrentSize(); i++) {
        cout << "\n - rows = " << DA.data[i].row << " / columns = " << DA.data[i].column;
    }
    DA.Add(c);
    cout << "\nNew current size :" << DA.GetCurrentSize() << "\nNew current capacity : " << DA.GetCapacity();
    cout << "\n Array contain :";
    for (int i = 0; i < DA.GetCurrentSize(); i++) {
        cout << "\n - rows = " << DA.data[i].row << " / columns = " << DA.data[i].column;
    }
    DA.Shrink();
    cout << "\nAfter shrink, new current size :" << DA.GetCurrentSize() << "\nNew current capacity : " << DA.GetCapacity();

    return 0;
}
