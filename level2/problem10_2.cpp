#include <iostream>
#include <string>
using namespace std;
long long readNumber()
{
    long long number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < 0 || 1000000000000000000 < number)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:10^18]: ";
        cin >> number;
    }
    return number;
}
string convertToString(long long number)
{
    string stringNumber = to_string(number);
    return stringNumber;
}
void printDigits(string stringNumber)
{
    cout << "===================================";
    for (unsigned short i = 0; i < stringNumber.length(); i++)
    {
        cout << '\n'
             << stringNumber[i];
    }
}
int main()
{
    printDigits(convertToString(readNumber()));
    return 0;
}