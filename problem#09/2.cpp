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
short countDigit(long long number)
{
    short digit = 0;
    unsigned short length = sizeof(number) / sizeof(number % 10);
  
      
}
void printCountDigit(const short count, const short digit)
{
    string time = " Time.";
    if (count > 1)
        time = " Times.";
    cout << "==============================\n"
         << "Digit " << digit << " Frequency is " << count << time;
}
int main()
{
    long long number = readNumber();
    short digit = readDigit();
    printCountDigit(countDigit(number, digit), digit);
    return 0;
}