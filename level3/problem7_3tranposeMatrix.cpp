#include <iostream>
using namespace std;
void createArray(short array[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            array[i][j] = j + 1 + i * length;
        }
    }
}
void printArray(const short array[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }
}
void swappingTwo(short &a, short &b)
{
    short temp = a;
    a = b;
    b = temp;
}
void transposeMatrix(short array[][3], const short length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = i; j < length; j++)
        {
            swappingTwo(array[i][j], array[j][i]);
        }
    }
}
int main()
{
    short array[3][3];
    createArray(array, 3);
    cout << "The Following Is A (3 x 3)  Matrix: \n";
    printArray(array, 3);
    transposeMatrix(array, 3);
    cout << "\nThe Following Is Tranpose Matrix: \n";
    printArray(array, 3);
    return 0;
}