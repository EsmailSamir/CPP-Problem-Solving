#include <iostream>
using namespace std;
long long readNumber()
{
    long long number;
    cout << "Enter A Number: \n";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < 0 || number > 1000000000000000000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Integer Numeric Value [0:10^18]: \n";
        cin >> number;
    }
    return number;
}
short readDigit()
{
    short digit;
    cout << "Enter Any Digit: ";
    cin >> digit;
    while (cin.fail() || cin.peek() != '\n' || digit < 0 || digit > 9)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Integer Numeric Value [0:9]: \n";
        cin >> digit;
    }
    return digit;
}
short countDigit(long long number, const short digit)
{
    short count = 0;
    if (number == 0 && digit == 0)
    {
        count++;
        return count;
    }
    while (number > 0)
    {
        if (number % 10 == digit)
            count++;
        number /= 10;
    }
    return count;
}
void printCountDigit(const short count, const short digit)
{
    cout << "=============================\n";
    if (count == 0)
    {
        cout << "This Digit Is Not In Number.";
        return;
    }
    string time = " Time";
    if (count > 1)
        time += 's';
    cout << "Digit " << digit << " Frequency is " << count << time;
}
int main()
{
    long long number = readNumber();
    short digit = readDigit();
    printCountDigit(countDigit(number, digit), digit);
    return 0;
}