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
short countDaysInMonth(const bool leapYear, const short month)
{
    if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
        return month == 2 ? (leapYear ? 29 : 28) : 30;
    return 31;
}
Date addDaysToDate(Date newDate, short daysToAdd)
{
    while (daysToAdd > 0)
    {
        bool leapYear = isLeapYear(newDate.year);
        short daysInMonth = countDaysInMonth(leapYear, newDate.month);
        short remainDaysInYear = 0;
        for (short i = newDate.month; i <= 12; i++)
        {
            remainDaysInYear += countDaysInMonth(leapYear, i);
        }
        remainDaysInYear -= newDate.day;
        if (daysToAdd <= (daysInMonth - newDate.day))
        {
            newDate.day += daysToAdd;
            break;
        }
        else if (daysToAdd <= remainDaysInYear)
        {
            daysToAdd -= (daysInMonth - newDate.day);
            newDate.month++;
            newDate.day = 0;
        }
        else
        {
            daysToAdd -= remainDaysInYear;
            newDate.year++;
            newDate.month = 1;
            newDate.day = 0;
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
    currentDate.day = readNumber(1, countDaysInMonth(leapYear, currentDate.month));
    cout << "\nHow Many Days To Add : ";
    short daysToAdd = readNumber(0, 32600);
    Date newDate = addDaysToDate(currentDate, daysToAdd);
    cout << "\n\nDate After Adding [" << daysToAdd << "] Is : "
         << newDate.year << "/" << newDate.month << "/" << newDate.day << "\n";
    return 0;
}