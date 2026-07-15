#include <iostream>
using namespace std;
void readlimit(int &limit)
{
    cout << "Enter A Limit: ";
    cin >> limit;
    while (cin.fail() || limit < 2 || cin.peek() != '\n' || limit > 100000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [2:100,000]: ";
        cin >> limit;
    }
}
bool testPrimeNumber(const int number)
{
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int limit;
    readlimit(limit);
    cout << "=========================\nThe Prime Numbers Is:\n";
    for (int number = 2; number <= limit; number++)
    {
        if (testPrimeNumber(number))
            cout << number << '\n';
    }
    return 0;
}