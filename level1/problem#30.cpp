#include <iostream>
using namespace std;
short int readLimit()
{
    short int limit;
    cout << "Enter Limit: ";
    cin >> limit;
    while (cin.fail() || limit < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter Limit: ";
        cin >> limit;
    }
    return limit;
}
unsigned long long factLimit(short int limit)
{
    unsigned long long fact = 1;
    for (short int i = limit; i >= 1; i--)
    { 
        fact = fact * i;
    }
    return fact;
}
void printFactLimit(unsigned long long fact)
{
    cout << "============================================\n"
         << "Factorial Numbers From 1 To Limit = " << fact;
}
int main()
{
    printFactLimit(factLimit(readLimit()));
    return 0;
}