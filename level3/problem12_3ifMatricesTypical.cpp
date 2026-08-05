#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
void createRandomMatrix(short matrix[][3],
                        const short rows, const short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            matrix[i][j] = limitsOfRandom(1, 10);
        }
    }
}
void printMatrix(const short matrix[][3],
                 const short rows, const short columns)
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
bool compareElementsInMatrices(
    const short matrix1[][3], const short matrix2[][3],
    const short rows, const short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix1[3][3], matrix2[3][3];
    createRandomMatrix(matrix1, 3, 3);
    cout << "Matrix1:\n";
    printMatrix(matrix1, 3, 3);
    createRandomMatrix(matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    printMatrix(matrix2, 3, 3);
    if (compareElementsInMatrices(matrix1, matrix2, 3, 3))
        cout << "\n\nYes, Matrices Are Typical.\n";
    else
        cout << "\n\nNo, Matrices Are Not Typical.\n";
    return 0;
}