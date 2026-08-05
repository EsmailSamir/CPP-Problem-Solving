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
            matrix[i][j] = limitsOfRandom(0, 9);
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
            printf("%d\t", matrix[i][j]);
        }
        cout << "\n";
    }
}
bool checkScalarMatrix(const short matrix[][3],
                       const short rows, const short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (i == j && matrix[0][0] != matrix[i][j])
                return false;
            else if (i != j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix[3][3];
    createRandomMatrix(matrix, 3, 3);
    cout << "Matrix:\n";
    printMatrix(matrix, 3, 3);
    if (checkScalarMatrix(matrix, 3, 3))
        cout << "\nYes: Matrix Is Scalar.\n";
    else
        cout << "\nNo: Matrix Is Not Scalar.\n";
    return 0;
}