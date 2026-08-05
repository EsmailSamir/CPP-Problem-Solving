#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
const short rows = 3, columns = 3;
void createRandomMatrix(short matrix[rows][columns])
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            matrix[i][j] = limitsOfRandom(1, 99);
        }
    }
}
void printMatrix(const short matrix[rows][columns])
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            printf("%02d\t", matrix[i][j]);
        }
        cout << "\n";
    }
}
bool isNumInMatrix(const short matrix[rows][columns], const short num)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (matrix[i][j] == num)
                return true;
        }
    }
    return false;
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix[rows][columns], number;
    createRandomMatrix(matrix);
    cout << "Matrix:\n";
    printMatrix(matrix);
    cout << "\nEnter Number To Look For In Matrix: \n";
    number = readNumber(1, 99);
    if (isNumInMatrix(matrix, number))
        cout << "\nYes, Number " << number << " Is In Matrix\n";
    else
        cout << "\nNo, Number " << number << " Is Not In Matrix\n";
    return 0;
}