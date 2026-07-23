#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n--Making A Randomn Array And Copy Prime--\n\n"
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
void addElementForArray(const short number,
                        short &length_c, short array_c[])
{
    array_c[length_c] = number;
    length_c++;
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
void copyArrayByElementForPrime(const short array_b[], const short length,
                                short &length_c, short array_c[])
{
    for (short i = 0; i < length; i++)
    {
        if (testPrimeNumber(array_b[i]))
            addElementForArray(array_b[i], length_c, array_c);
    }
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
int main()
{
    srand((unsigned)time(NULL));
    short array_b[100], array_c[100],
        length = readLength(), length_c = 0;
    createArray(array_b, length);
    cout << "====================================\n"
         << "Array 1 Elements: \n";
    printArray(array_b, length);
    copyArrayByElementForPrime(array_b, length, length_c, array_c);
    cout << "====================================\n"
         << "Array 2 Prime Number:\n";
    printArray(array_c, length_c);
    return 0;
}