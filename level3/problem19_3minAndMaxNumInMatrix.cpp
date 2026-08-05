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
void minAndMaxNumInMatrix(const short matrix[rows][columns],
                          short &min, short &max)
{
    min = max = matrix[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (min > matrix[i][j])
                min = matrix[i][j];
            else if (max < matrix[i][j])
                max = matrix[i][j];
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix1[rows][columns], min, max;
    createRandomMatrix(matrix1);
    cout << "Matrix 1:\n";
    printMatrix(matrix1);
    minAndMaxNumInMatrix(matrix1, min, max);
    cout << "\nMiNimum Number Is : " << min
         << "\nMaXimum Number Is : " << max;
    return 0;
}