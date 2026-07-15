#include <iostream>
using namespace std;
void readSecond(long &seconds)
{
    cout << "Enter Seconds: ";
    cin >> seconds;
    while (cin.fail() || seconds < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value >= 0: ";
        cin >> seconds;
    }
}
void calcTime(int &days, int &hours, int &minutes, long &seconds)
{
    days = seconds / 86400;
    int remainder = seconds % 86400;
    hours = remainder / 3600;
    remainder = remainder % 3600;
    minutes = remainder / 60;
    seconds = remainder % 60;
}
void printTime(const int &days, const int &hours, const int &minutes, const long &seconds)
{
    cout << "===========================\n"
         << "Dy : Hr : Mn : Sc\n"
         << days << " : " << hours << " : " << minutes << " : " << seconds;
}
int main()
{
    long seconds;
    int days, hours, minutes;
    readSecond(seconds);
    calcTime(days, hours, minutes, seconds);
    printTime(days, hours, minutes, seconds);
    return 0;
}