#include <iostream>
#include <limits>
using namespace std;
struct date
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
short DayOrderInYear(const bool leapYear, const short dayNum, const short month)
{
    short totalDays = 0;
    for (short i = 1; i < month; i++)
    {
        totalDays += countDaysInMonth(leapYear, i);
    }
    return totalDays + dayNum;
}
date countMonthsAndDaysFromDayOrder(short dayOrder, const bool leapYear)
{
    date creatDate;
    short daysInMonth = 0, i = 1;
    for (; i <= 12; i++)
    {
        daysInMonth = countDaysInMonth(leapYear, i);
        if (daysInMonth < dayOrder && i < 12)
            dayOrder -= daysInMonth;
        else
            break;
    }
    creatDate.month = i;
    creatDate.day = dayOrder;
    return creatDate;
}
int main()
{
    cout << "Enter Year To Check  : ";
    short year = readNumber(1, 32600);
    bool leapYear = isLeapYear(year);
    cout << "\nEnter Month To Check : ";
    short month = readNumber(1, 12);
    short daysInMonth = countDaysInMonth(leapYear, month);
    cout << "\nEnter Day To Check   : ";
    short dayNum = readNumber(1, daysInMonth);
    short dayOrder = DayOrderInYear(leapYear, dayNum, month);
    date creatDate = countMonthsAndDaysFromDayOrder(dayOrder, leapYear);
    creatDate.year = year;
    cout << "\nNumber Of Days From Begining Of Year = " << dayOrder
         << "\n\nDate For [" << dayOrder << "] Is : "
         << creatDate.year << "(y)/ " << creatDate.month << "(m)/ " << creatDate.day << "(d)\n";
    return 0;
}