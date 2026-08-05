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
short countZeroInMatrix(const short matrix[][3], const short rows,
                        const short columns)
{
    short count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (matrix[i][j] == 0)
                count++;
        }
    }
    return count;
}
int main()
{
    srand((unsigned)time(NULL));
    const short rows = 3, columns = 3, mid = rows * columns / 2;
    short matrix[rows][columns];
    createRandomMatrix(matrix, rows, columns);
    cout << "Matrix:\n";
    printMatrix(matrix, rows, columns);
    if (countZeroInMatrix(matrix, rows, columns) > mid)
        cout << "\nYes: Matrix Is Sparse.\n";
    else
        cout << "\nNo: Matrix Is Not Sparse.\n";
    return 0;
}