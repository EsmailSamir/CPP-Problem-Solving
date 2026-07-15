#include <iostream>
using namespace std;
long readNumber()
{
    long number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < 0 || 100000000 < number)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:100,000,000]: ";
        cin >> number;
    }
    return number;
}
int sumDigits(long number)
{
    int sum = 0;
    while (number > 0)
    {

        sum += number % 10;
        number /= 10;
    }
    return sum;
}
void printSum(const int sum)
{
    cout << "============================\nSum Of Digits = "
         << sum << '\n';
}
int main()
{
    printSum(sumDigits(readNumber()));
    return 0;
}