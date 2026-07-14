#include <iostream>
using namespace std;
int readLimit()
{
    int limit;
    cout << "Enter A limit: ";
    cin >> limit;
    while (cin.fail() || limit < 2 || cin.peek() != '\n' || limit > 100000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [2:100,000]: ";
        cin >> limit;
    }
    return limit;
}
int sumDivisiors(const int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
            sum += i;
    }
    return sum;
}
bool testPerfectNumber(const int number)
{
    return (sumDivisiors(number) == number);
}
void printPerfectToLimit(const int limit)
{
    cout << "\n=======================================\n"
         << "ALL PERFECT NUMBERS FROM 1 TO " << limit << '\n';
    for (int j = 1; j <= limit; j++)
    {
        if (testPerfectNumber(j))
            cout << j << '\n';
    }
}
int main()
{
    int limit = readLimit();
    printPerfectToLimit(limit);
    return 0;
}