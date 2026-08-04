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
void printOneRow(const short matrix[][3],
                 const short row, const short columns)
{

    for (short i = 0; i < columns; i++)
    {
        printf("%0*d\t", 2, matrix[row][i]);
    }
}
short countMid(const short rows)
{
    return rows / 2;
}
void printOneColumn(const short matrix[][3],
                    const short rows, const short column)
{
    for (short i = 0; i < rows; i++)
    {
        printf("%0*d\t\n", 2, matrix[i][column]);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short matrix[3][3], mid = countMid(3);
    createRandomMatrix(matrix, 3, 3);
    cout << "Matrix 1:\n";
    printMatrix(matrix, 3, 3);
    cout << "\nMiddle Row Of Matrix:\n";
    printOneRow(matrix, mid, 3);
    cout << "\n\nMiddle Column Of Matrix:\n";
    printOneColumn(matrix, 3, mid);
    return 0;
}