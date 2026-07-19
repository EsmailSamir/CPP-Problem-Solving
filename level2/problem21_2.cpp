#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLimits()
{
    short keys;
    cout << "\n--Generate Random Keys For Passwords--\n\n"
         << "Enter How Many Keys: ";
    cin >> keys;
    while (cin.fail() || cin.peek() != '\n' || keys < 0 || 1000 < keys)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numiric Value\n"
             << "Enter How Many Keys: ";
        cin >> keys;
    }
    return keys;
}
void printRandomKeys(short keys)
{
    cout << "=============================";
    for (short i = 1; i <= keys; i++)
    {
        cout << "\nKey [" << i << "] : ";
        for (short j = 1; j <= 4; j++)
        {
            for (short k = 1; k <= 4; k++)
            {
                cout << char(rand() % ('Z' - 'A' + 1) + 'A');
            }
            if (j < 4)
                cout << '-';
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    printRandomKeys(readLimits());
    return 0;
}