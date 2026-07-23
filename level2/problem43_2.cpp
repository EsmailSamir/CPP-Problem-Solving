#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n-Making A Randomn Array And Count Even Numbers-\n\n"
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
short countEvenNumbers(const short array[], const short length)
{
    short even = 0;
    for (short i = 0; i < length; i++)
    {
        if (array[i] % 2 == 0)
            even++;
    }
    return even;
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
void printResultCountEven(const short array[], const short length)
{
    cout << "Even Numbers count is: "
         << countEvenNumbers(array, length) << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    short array[100], length = readLength();
    createArray(array, length);
    cout << "\n=======================================\n"
         << "Array Elements: \n";
    printArray(array, length);
    cout << "\n=======================================\n";
    printResultCountEven(array, length);
    return 0;
}