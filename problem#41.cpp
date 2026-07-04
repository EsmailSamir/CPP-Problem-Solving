#include <iostream>
using namespace std;
void readHours(float &hours)
{
    cout << "Enter Hours: ";
    cin >> hours;
    while (cin.fail() || hours <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Numeric Value > 0: ";
        cin >> hours;
    }
}
void calcTime(float &seconds, float &minutes, const float &hours,
              float &days, float &weeks, float &months, float &years)
{
    seconds = hours * 3600.0;
    minutes = seconds / 60.0;
    days = hours / 24.0f;
    weeks = days/ 7.0f;
    months = days / 30.0f;
    years = months / 12.0f;
}
void printAllTime(const float &seconds, const float &minutes, const float &hours,
                  const float &days, const float &weeks, const float &months, const float &years)
{
    cout << "========================\n"
         << "Seconds = " << seconds << "\n"
         << "Minutes = " << minutes << "\n"
         << "Hours = " << hours << "\n"
         << "Days = " << days << "\n"
         << "Weeks = " << weeks << "\n"
         << "Months = " << months << "\n"
         << "Years = " << years << "\n";
}
int main()
{
    float seconds, minutes, hours, days, weeks, months, years;
    readHours(hours);
    calcTime(seconds, minutes, hours, days, weeks, months, years);
    printAllTime(seconds, minutes, hours, days, weeks, months, years);
    return 0;
}