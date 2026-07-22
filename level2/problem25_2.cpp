#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n-Making A Random Array And Read Minimum Number In-\n\n"
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
short minimumNumberInArray(const short array[], const short length)
{
    short minimumNumber = array[0];
    for (short i = 1; i < length; i++)
    {
        if (array[i] < minimumNumber)
            minimumNumber = array[i];
    }
    return minimumNumber;
}
void printArray(const short array[], const short length)
{
    cout << "[";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
        {
            cout << array[i] << ", ";
            if ((i + 1) % 10 == 0)
                cout << '\n';
        }
        else
            cout << array[i] << "]\n";
    }
}
void printMinimumNumberInArray(const short array[], const short length)
{
    cout << "========================================\n"
         << "Minimum Number In Array = " << minimumNumberInArray(array, length) << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(), array[100];
    createArray(array, length);
    cout << "========================================\n"
         << "Random Array : \n";
    printArray(array, length);
    printMinimumNumberInArray(array, length);
    return 0;
}