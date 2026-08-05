#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
void createRandomMatrix(short matrix[][3], const short columns, const short rows)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            matrix[i][j] = limitsOfRandom(1, 10);
        }
    }
}
void printMatrix(const short matrix[][3], const short rows, const short columns)
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
short SumOfMatrix(const short matrix[][3], const short rows, const short columns)
{
    short sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}
bool equalMatrices(const short matrix1[][3],
                   const short matrix2[][3],
                   const short rows, const short columns)
{
    return SumOfMatrix(matrix1, columns, rows) == SumOfMatrix(matrix2, columns, rows);
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
    cout << "\nSum Of Matrix1 Is: "
         << SumOfMatrix(matrix1, 3, 3);
    cout << "\nSum Of Matrix2 Is: "
         << SumOfMatrix(matrix2, 3, 3);
    if (equalMatrices(matrix1, matrix2, 3, 3))
        cout << "\n\nYes, Matrices Are Equal.\n";
    else
        cout << "\n\nNo, Matrices Are Not Equal.\n";
    return 0;
}