#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n-Making A Random Array And Sum All Numbers In-\n\n"
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
unsigned int sumNumbersInArray(const short array[], const short length)
{
    unsigned int sumNumbers = 0;
    for (short i = 0; i < length; i++)
    {
        sumNumbers += array[i];
    }
    return sumNumbers;
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
void printSumNumbersInArray(const short array[], const short length)
{
    cout << "========================================\n"
         << "Sum Of All Numbers In Array = "
         << sumNumbersInArray(array, length) << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(), array[100];
    createArray(array, length);
    printArray(array, length);
    cout << "========================================\n"
         << "Random Array : \n";
    printSumNumbersInArray(array, length);
    return 0;
}