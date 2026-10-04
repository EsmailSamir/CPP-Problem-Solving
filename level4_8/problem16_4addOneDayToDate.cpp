#include <iostream>
#include <limits>
using namespace std;
struct Date
{
    short year;
    short month;
    short day;
};
short readNumber(const short from, const short to)
{
    short Number = 0;
    cin >> Number;
    while (cin.fail() || cin.peek() != '\n' || Number < from || to < Number)
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
        cout << "Enter Number: ";
        cin >> Number;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return Number;
}
bool isLeapYear(const short year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
short countDaysInMonth(const short year, const short month)
{
    if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
        return month == 2 ? (isLeapYear(year) ? 29 : 28) : 30;
    return 31;
}
Date addOneDayToDate(Date newDate)
{
    bool leapYear = isLeapYear(newDate.year);
    short daysInMonth = countDaysInMonth(newDate.year, newDate.month);
    if (newDate.day < daysInMonth)
        newDate.day++;
    else
    {
        if (newDate.month < 12)
        {
            newDate.month++;
            newDate.day = 1;
        }
        else
        {
            newDate.year++;
            newDate.month = 1;
            newDate.day = 1;
        }
    }
    return newDate;
}
int main()
{
    Date currentDate;
    cout << "Enter Year To Check  : ";
    currentDate.year = readNumber(1, 32600);
    bool leapYear = isLeapYear(currentDate.year);
    cout << "\nEnter Month To Check : ";
    currentDate.month = readNumber(1, 12);
    cout << "\nEnter Day To Check   : ";
    currentDate.day = readNumber(1, countDaysInMonth(currentDate.year, currentDate.month));
    Date newDate = addOneDayToDate(currentDate);
    cout << "\n\nDate After Adding One Day Is : "
         << newDate.year << "/" << newDate.month << "/" << newDate.day << "\n";
    return 0;
}