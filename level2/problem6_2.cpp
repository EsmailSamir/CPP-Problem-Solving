#include <iostream>
using namespace std;
long long readNumber()
{
    long long number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' 
    || number < 0 || 1000000000000000000 < number)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:10^18]: ";
        cin >> number;
    }
    return number;
}
int sumDigits(long long number)
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
    cout << "==================================\n"
         << "Sum Of Digits = " << sum;
}
int main()
{
    printSum(sumDigits(readNumber()));
    return 0;
}