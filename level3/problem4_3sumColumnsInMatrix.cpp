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
short sumColumn(const short array[][3], const short numbercolumn, const short rows)
{
    short sum = 0;
    for (short i = 0; i < rows; i++)
    {
        sum += array[i][numbercolumn];
    }
    return sum;
}
void printSumOfColumns(const short array[][3], const short columns, const short rows)
{
    for (short i = 0; i < columns; i++)
    {
        cout << "Sum Of column " << i + 1
             << " = " << sumColumn(array, i, rows) << '\n';
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short array[3][3];
    createRandomArray2(array, 3);
    cout << "The Following Is A 3x3 Random Matrix: \n";
    printArray(array, 3);
    printSumOfColumns(array, 3, 3);
    return 0;
}