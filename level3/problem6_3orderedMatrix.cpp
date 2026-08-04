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
int main()
{
    short array[3][3];
    createArray(array, 3);
    cout << "The Following Is A 3x3  Matrix: \n";
    printArray(array, 3);
    return 0;
}