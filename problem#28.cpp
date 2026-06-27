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
short int sumLimit(short int limit)
{
    int sum = 0;
    for (short int i = 1; i <= limit; i += 2)
    {
        sum += i;
    }
    return sum;
}
void printSumLimit(int sum)
{
    cout << "=====================\n"
         << "Sum Odd Numbers To Limit = " << sum;
}
int main()
{
    printSumLimit(sumLimit(readLimit()));
    return 0;
}