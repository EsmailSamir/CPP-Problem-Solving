#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
void createRandomMatrix(short matrix[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            matrix[i][j] = limitsOfRandom(1, 10);
        }
    }
}
void printMatrix(const short matrix[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            printf("%0*d\t", 2, matrix[i][j]);
        }
        cout << "\n";
    }
}
void mulTwoMatrix(const short matrix1[][3],
                  const short matrix2[][3],
                  short mulMatrix3[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            mulMatrix3[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix1[3][3], matrix2[3][3], mulMatrix3[3][3];
    createRandomMatrix(matrix1, 3);
    cout << "The Following Is A 3x3 Random Matrix (1): \n";
    printMatrix(matrix1, 3);
    createRandomMatrix(matrix2, 3);
    cout << "\n\nThe Following Is A 3x3 Random Matrix (2): \n";
    printMatrix(matrix2, 3);
    mulTwoMatrix(matrix1, matrix2, mulMatrix3, 3);
    cout << "\n\nThe Following Is A 3x3 multiplied Matrix (3): \n";
    printMatrix(mulMatrix3, 3);
    return 0;
}