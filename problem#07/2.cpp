#include <iostream>
using namespace std;
long long readNumber()
{
    long long number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || number < 0 || cin.peek() != '\n' || number > 1000000000000000000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:10^18]: ";
        cin >> number;
    }
    return number;
}
void printReversed(long long number)
{
    cout << "=====================================\nReverse Is: \n";
    if (number == 0)
    {
        cout << '0';
        return;
    }
    while (number > 0)
    {
        cout << number % 10;
        number /= 10;
    }
}
int main()
{
    printReversed(readNumber());
    return 0;
}