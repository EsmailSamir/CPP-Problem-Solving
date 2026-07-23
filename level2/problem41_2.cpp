#include <iostream>
using namespace std;
short readLength()
{
    short length;
    cout << "\n-Making An Array And Test Palindrome-\n\n"
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
void createArray(short array[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        cout << "Enter Element[" << i + 1 << "]: ";
        cin >> array[i];
        while (cin.fail() || cin.peek() != '\n'
          || array[i] < 1 || 100 < array[i])
        {
            cin.clear();
            cin.ignore(100000000, '\n');
            cout << "Enter A Positive Numeric Value [1, 100]\n"
                 << "Enter Element[" << i + 1 << "]: ";
            cin >> array[i];
        }
    }
}
bool testPalindrome(const short array[], const short length)
{
    for (short i = 0; i < length / 2; i++)
    {
        if (array[i] != array[length - 1 - i])
            return false;
    }
    return true;
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
void printIfPalindrome(const short array[], const short length)
{
    if (testPalindrome(array, length))
        cout << "Yes, Array Is Palindrome\n";
    else
        cout << "No, Array Isn't Palindrome\n";
}
int main()
{
    short array[100], length = readLength();
    cout << "\n=======================================\n";
    createArray(array, length);
    cout << "\n=======================================\n"
         << "Array Elements: \n";
    printArray(array, length);
    cout << "\n=======================================\n";
    printIfPalindrome(array, length);
    return 0;
}