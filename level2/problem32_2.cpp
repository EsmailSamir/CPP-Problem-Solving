#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n---Making A Random Array And Reverse It---\n\n"
         << "Enter length: ";
    cin >> length;
    while (cin.fail() || cin.peek() != '\n'
        || length < 1 || 100 < length)
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
void reverseArray(const short array[],
                  short array_Copy[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        array_Copy[i] = array[length - 1 - i];
    }
}
void printArray(const short array[], const short length)
{
    cout << " [";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
            cout << array[i] << ", ";
        else
            cout << array[i] << "]\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(),
          array[100], array_Copy[100];
    createArray(array, length);
    cout << "========================================\n"
         << "The Random Array:\n";
    printArray(array, length);
    reverseArray(array, array_Copy, length);
    cout << "========================================\n"
         << "Reverse Same Random Array:\n";
    printArray(array_Copy, length);
    return 0;
}