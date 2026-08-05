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
            printf("%0*d\t", 2, matrix[i][j]);
        }
        cout << "\n";
    }
}
bool isNumInMatrix(const short matrix[rows][columns],
                   const short num)
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
void printIntersectedNumbers(const short matrix1[rows][columns],
                             const short matrix2[rows][columns])
{
    short countformat = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (isNumInMatrix(matrix2, matrix1[i][j]))
            {
                printf("%0*d\t", 2, matrix1[i][j]);
                countformat++;
                if (countformat % columns == 0)
                    cout << "\n";
            }
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix1[rows][columns], matrix2[rows][columns];
    createRandomMatrix(matrix1);
    cout << "Matrix 1:\n";
    printMatrix(matrix1);
    createRandomMatrix(matrix2);
    cout << "\nMatrix 2:\n";
    printMatrix(matrix2);
    cout << "\nIntersected Numbers Are:\n";
    printIntersectedNumbers(matrix1, matrix2);
    return 0;
}