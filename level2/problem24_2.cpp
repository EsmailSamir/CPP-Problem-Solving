#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n-Making A Random Array And Read Max Number In-\n\n"
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
short limitsOfRandom(short from, short to)
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
short maxNumberInArray(const short array[], const short length)
{
    short maxNumber = array[0];
    for (short i = 1; i < length; i++)
    {
        if (array[i] > maxNumber)
            maxNumber = array[i];
    }
    return maxNumber;
}
void printArray(const short array[], const short length)
{
    cout << "========================================\n"
         << "Random Array : [";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
            cout << array[i] << ',';
        else

            cout << array[i] << "]\n";
    }
}
void printMaxNumberInArray(const short maxNumber)
{
    cout << "========================================\n"
         << "Max Number In Array = " << maxNumber << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(), array[100];
    createArray(array, length);
    printArray(array, length);
    printMaxNumberInArray(maxNumberInArray(array, length));
    return 0;
}