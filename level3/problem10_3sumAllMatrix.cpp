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
            array[i][j] = limitsOfRandom(1, 10);
        }
    }
}
void printArray(const short array[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            printf("%0*d\t", 2, array[i][j]);
        }
        cout << "\n";
    }
}
short SumOfMatrix(const short array[][3], const short columns, const short rows)
{
    short sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            sum += array[i][j];
        }
    }
    return sum;
}
int main()
{
    srand((unsigned)time(NULL));
    short array[3][3];
    createRandomArray2(array, 3);
    cout << "Matrix1:\n";
    printArray(array, 3);
    cout << "\nSum Of Matrix Is: "
         << SumOfMatrix(array, 3, 3);
    return 0;
}