#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n---Making A Random Array And Copy prime---\n\n"
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
bool testPrimeNumber(const int number)
{
    if (number == 1)
        return false;
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
short CopyArrayForPrimeNumber(const short array[],
                              const short length, short primeArray[])
{
    short j = 0;
    for (short i = 0; i < length; i++)
    {
        if (testPrimeNumber(array[i]))
        {
            primeArray[j] = array[i];
            j++;
        }
    }
    return j;
}
void printArray(short array[], short length)
{
    cout << "[";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
            cout << array[i] << ',';
        else

            cout << array[i] << "]\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(),
          array[100], primeArray[100];
    createArray(array, length);
    cout << "=================================================\n"
         << "Random Array (1): \n";
    printArray(array, length);
    cout << "=================================================\n"
         << "Prime Numbers In Array : \n";
    printArray(primeArray,
               CopyArrayForPrimeNumber(array, length, primeArray));
    return 0;
}