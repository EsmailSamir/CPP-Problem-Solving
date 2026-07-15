#include <iostream>
using namespace std;
int readNumbers()
{
    int number;
    cout << "Enter An Integer Number: ";
    cin >> number;
    while (cin.fail() || number < 2)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value >= 2: ";
        cin >> number;
    }
    return number;
}
bool testNumber(int number)
{
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
void printResult(bool testPrime)
{
    if (testPrime)
        cout << "PRIME";
    else
        cout << "NOT PRIME";
}
int main()
{
    printResult(testNumber(readNumbers()));
    return 0;
} 