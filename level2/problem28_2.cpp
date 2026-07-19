#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n-----Making A Random Array And Copy It-----\n\n"
         << "Enter length: ";
    cin >> length;
    while (cin.fail() || cin.peek() != '\n' || length < 1 || 100 < length)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value [1, 100]\n"
             << "Enter length: ";
        cin >> length;
    }
    return length;
}
short limitsOfRandom(const short from, const short to)
{
    return rand() % (to - from + 1) + from;
}
void createArray(short array[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        array[i] = limitsOfRandom(1, 100);
    }
}
void printArray(const short array[], const short length, const short numArray)
{
    cout << "========================================\n"
         << "Random Array (" << numArray << "):" << '\n'
         << "[";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
            cout << array[i] << ',';
        else

            cout << array[i] << "]\n";
    }
}
void makeCopyArray(const short array[],
                   const short length, short copyArray[])
{
    for (short i = 0; i < length; i++)
    {
        copyArray[i] = array[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(),
          array[100], copyArray[100];
    createArray(array, length);
    printArray(array, length, 1);
    makeCopyArray(array, length, copyArray);
    printArray(copyArray, length, 2);
    return 0;
}