#include <iostream>
using namespace std;
long readNumber()
{
    long number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || number < 0 || cin.peek() != '\n' || number >= 100000000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:100,000,000]: ";
        cin >> number;
    }
    return number;
}
void printReversed(long number)
{
    cout << "============================\n";
    if (number == 0)
    {
        cout << '0';
        return;
    }
    while (number > 0)
    {
        cout << number % 10 << '\n';
        number = number / 10;
    }
}
int main()
{
    printReversed(readNumber());
    return 0;
}