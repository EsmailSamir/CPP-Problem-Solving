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
short countNumInMatrix(const short matrix[][3], const short rows,
                       const short columns, const short num)
{
    short count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (matrix[i][j] == num)
                count++;
        }
    }
    return count;
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix[3][3], number;
    createRandomMatrix(matrix, 3, 3);
    cout << "Matrix:\n";
    printMatrix(matrix, 3, 3);
    cout << "\nEnter Number You Need To Count In Matrix: \n";
    number = readNumber(0, 9);
    cout << "\nNumber " << number << " Count In Matrix Is = "
         << countNumInMatrix(matrix, 3, 3, number) << "\n";
    return 0;
}