#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
const short rows = 4, columns = 4;
void createRandomMatrix(short matrix[rows][columns])
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            matrix[i][j] = limitsOfRandom(1, 9);
        }
    }
}
void printMatrix(const short matrix[rows][columns])
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        cout << "\n";
    }
}
bool isPalindromeMatrix(const short matrix[rows][columns])
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns / 2; j++)
        {
            if (matrix[i][j] != matrix[i][columns - 1 - j])
                return false;
        }
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix[rows][columns];
    createRandomMatrix(matrix);
    cout << "Matrix:\n";
    printMatrix(matrix);
    if (isPalindromeMatrix(matrix))
        cout << "\nYes: Matrix Is Palindrome.\n";
    else
        cout << "\nNo: Matrix Is Not Palindrome.\n";
    return 0;
}