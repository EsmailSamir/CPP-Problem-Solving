#include <iostream>
using namespace std;
long long readNumber()
{
    long long number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < 0 || number > 1000000000000000000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:10^18]: ";
        cin >> number;
    }
    return number;
}
short countDigit(long long number, const short digit)
{
    short frequency = 0;
    if (number == 0 && digit == 0)
    {
        frequency++;
        return frequency;
    }
    while (number > 0)
    {
        if (number % 10 == digit)
            frequency++;
        number /= 10;
    }
    return frequency;
}
void printCountDigit(const long long number)
{
    cout << "=================================";

    for (short i = 0; i <= 9; i++)
    {
        short frequency = countDigit(number, i);
        string time = " Time";
        if (frequency > 0)
        {
            if (frequency > 1)
                time += 's';
            cout << '\n'
                 << "Digit " << i << " Frequency is "
                 << frequency << time;
        }
    }
}
int main()
{
    printCountDigit(readNumber());
    return 0;
}