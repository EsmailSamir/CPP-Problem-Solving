#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
void createRandomArray2(short array[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            array[i][j] = limitsOfRandom(0, 100);
        }
    }
}
void printArray(const short array[][3], const short length)
{

    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short array[3][3];
    createRandomArray2(array, 3);
    cout << "The Following Is A 3x3 Random Matrix: \n";
    printArray(array, 3);
    return 0;
}