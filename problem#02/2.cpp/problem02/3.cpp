#include <iostream>
using namespace std;
int readNumber()
{
    int number;
    cout << "Enter A number: ";
    cin >> number;
    while (cin.fail() || number < 2 || cin.peek() != '\n' || number > 100000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [2:100,000]: ";
        cin >> number;
    }
    return number;
}
int sumDivisiors(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
            sum += i;
    }
    return sum;
}
bool testPerfectNumber(int number)
{
    return (sumDivisiors(number) == number);
}
void printPerfectNumber(int number, bool perfect)
{
    if (perfect)
        cout << number << " IS A PERFECT NUMBER.";
    else
        cout << number << " IS NOT PERFECT NUMBER.";
}
int main()
{
    int number = readNumber();
    printPerfectNumber(number, testPerfectNumber(number));
    return 0;
}