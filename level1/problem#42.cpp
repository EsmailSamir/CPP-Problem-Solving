#include <iostream>
using namespace std;
void readTime(float &days, float &hours, float &minutes, float &seconds)
{
    cout << "Enter Days: ";
    cin >> days;
    while (cin.fail() || days < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value >= 0: ";
        cin >> days;
    }
    cout << "Enter Hours: ";
    cin >> hours;
    while (cin.fail() || hours < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value >= 0: ";
        cin >> hours;
    }
    cout << "Enter Minutes: ";
    cin >> minutes;
    while (cin.fail() || minutes < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value >= 0: ";
        cin >> minutes;
    }
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
float calcSeconds(const float &days, const float &hours, const float &minutes, const float &seconds)
{
    return seconds + minutes * 60 + hours * 3600 + days * 86400;
}
void printTimeBySeconds(const float timeBySeconds)
{
    cout << "==============================\n"
         << timeBySeconds << " Seconds";
}
int main()
{
    float days, hours, minutes, seconds;
    readTime(days, hours, minutes, seconds);
    printTimeBySeconds(calcSeconds(days, hours, minutes, seconds));
    return 0;
}