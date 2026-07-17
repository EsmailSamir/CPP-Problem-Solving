#include <iostream>
using namespace std;
long long readNumber()
{
    long long number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || number < 0 || cin.peek() != '\n' 
    || number > 1000000000000000000)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:10^18]: ";
        cin >> number;
    }
    return number;
}
long long reversed(long long number)
{
    long long reverseNumber = 0;
    unsigned short remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        reverseNumber = reverseNumber * 10 + remainder;
    }
    return reverseNumber;
}
bool isPalindrome(long long number)
{
    return (number == reversed(number));
}
void printResult(const bool isMatch)
{
    cout << "=================================\n";
    if (isMatch)
        cout << "Yes, It's A Palindrome Number.";
    else
        cout << "No, It's NOT A Palindrome Number.";
}
int main()
{
    printResult(isPalindrome(readNumber()));
    return 0;
}