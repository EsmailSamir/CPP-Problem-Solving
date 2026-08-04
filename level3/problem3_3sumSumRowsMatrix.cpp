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
short sumRow(const short array[][3], const short columns, const short row)
{
    short sum = 0;
    for (short i = 0; i < columns; i++)
    {
        sum += array[row][i];
    }
    return sum;
}
void printSumOfRow(const short array[][3], const short columns, const short row)
{
    for (short i = 0; i < row; i++)
    {
        cout << "Sum Of Row " << i + 1
             << " = " << sumRow(array, columns, i) << '\n';
    }
}
void sumOfSumsRows(const short array[][3],
                   short arraySum[], const short columns, const short row)
{
    for (short i = 0; i < row; i++)
    {
        arraySum[i] = sumRow(array, columns, i);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short array[3][3], arraySum[3];
    createRandomArray2(array, 3);
    cout << "The Following Is A 3x3 Random Matrix: \n";
    printArray(array, 3);
    printSumOfRow(array, 3, 3);
    sumOfSumsRows(array, arraySum, 3, 3);
    cout << "\nArray For Sum Rows: \n";
    printArray(arraySum, 3);
    return 0;
}