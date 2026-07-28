#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
short countNegativeNumbers(const short array[], const short length)
{
    short negative = 0;
    for (short i = 0; i < length; i++)
    {
        if (array[i] < 0)
            negative++;
    }
    return negative;
}
void printResultCountNegative(const short array[], const short length)
{
    cout << "Negative Numbers count is: "
         << countNegativeNumbers(array, length) << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    short array[100], length = readNumber(1,100);
    createRandomArray(array, length);
    cout << "\n=======================================\n"
         << "Array Elements: \n";
    printArray(array, length);
    cout << "\n=======================================\n";
    printResultCountNegative(array, length);
    return 0;
}