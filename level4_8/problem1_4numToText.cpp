#include <iostream>
#include <string>
#include <limits>
using namespace std;
long readNumber(const long from, const long to)
{
    long number;
    cout << "Enter number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < from || to < number)
    {
        if (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            cout << "\nEnter A Positive Numeric Value["
                 << from << ", " << to << "]:\n";
        }
        cout << "Enter number: ";
        cin >> number;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}
string numberToText(const long number)
{
    if (number == 0)
        return "";
    if (number >= 1 && number <= 19)
    {
        static const string arr1[] =
            {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven",
             " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen",
             " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        return arr1[number];
    }
    if (number >= 20 && number <= 99)
    {
        static const string arr2[] =
            {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        return arr2[number / 10] + numberToText(number % 10);
    }
    if (number >= 100 && number <= 999)
        return numberToText(number / 100) + " Hundred" +
               numberToText(number % 100);
    if (number >= 1000 && number <= 999999)
        return numberToText(number / 1000) + " Thousand" +
               numberToText(number % 1000);
    if (number >= 1000000 && number <= 999999999)
        return numberToText(number / 1000000) + " Million" +
               numberToText(number % 1000000);
    else
        return numberToText(number / 1000000000) + " Billion" +
               numberToText(number % 1000000000);
}
int main()
{
    cout << "=================================================\n"
         << "            Convert Number To Text"
         << "\n=================================================\n";
    long number = readNumber(0, 1215752191);
    cout << "\nText:";
    if (number == 0)
        cout << " Zero.\n";
    else
        cout << numberToText(number) + ".\n";
    return 0;
}