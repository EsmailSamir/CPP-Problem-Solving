#include <iostream>
using namespace std;
short int readLimit()
{
    short int limit;
    cout << "Enter Limit: ";
    cin >> limit;
    while (cin.fail() || limit < 1)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter Limit: ";
        cin >> limit;
    }
    return limit;
}
void printLimit(short int limit)
{
    cout << "=====================\n";
    for (short int i = limit; i >= 1; i--)
    {
        cout << i << '\n';
    }
}
int main()
{
    printLimit(readLimit());
    return 0;
}