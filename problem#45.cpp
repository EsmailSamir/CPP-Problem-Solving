#include <iostream>
using namespace std;
short int readNumOfMonth()
{
    short int numOfMonth;
    cout << "Enter Num Of Month: ";
    cin >> numOfMonth;
    while (cin.fail() || numOfMonth < 1 || numOfMonth > 12)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value [1:12]\n"
             << "Enter Num Of Month: ";
        cin >> numOfMonth;
    }
    return numOfMonth;
}
void printMonth(const short int numOfMonth, const string months[])
{
    cout << "=======================\n"
         << months[numOfMonth - 1];
}
int main()
{
    const string months[] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};
    printMonth(readNumOfMonth(), months);
    return 0;
}
