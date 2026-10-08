#include <iostream>
#include <limits>
using namespace std;
struct Date
{
    short year;
    short month;
    short day;
};
struct stTwoDates
{
    Date startDate;
    Date endDate;
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
short countDaysInYear(const short year)
{
    return isLeapYear(year) ? 366 : 365;
}
short DayOrderInYear(const Date currentDate)
{
    short totalDays = 0;
    for (short i = 1; i < currentDate.month; i++)
    {
        totalDays += countDaysInMonth(currentDate.year, i);
    }
    return totalDays + currentDate.day;
}
int countDaysInDate(const short startYear, const Date date)
{
    int daysInYear = 0;
    for (short i = startYear; i < date.year; i++)
    {
        daysInYear += countDaysInYear(i);
    }
    return daysInYear + DayOrderInYear(date);
}
Date getStartPeriodDate()
{
    Date startDate;
    cout << "Start Period:\n"
         << "Enter Year To Check  : ";
    startDate.year = readNumber(1, 32600);
    cout << "Enter Month To Check : ";
    startDate.month = readNumber(1, 12);
    cout << "Enter Day To Check   : ";
    startDate.day = readNumber(1, countDaysInMonth(startDate.year, startDate.month));
    return startDate;
}
Date getEndPeriodDate(const Date startDate)
{
    Date endDate;
    cout << "\nEnd Period:\n"
         << "Enter Year To Check  : ";
    endDate.year = readNumber(startDate.year, 32600);
    cout << "Enter Month To Check : ";
    endDate.month = readNumber(((startDate.year == endDate.year) ? startDate.month : 1), 12);
    cout << "Enter Day To Check   : ";
    endDate.day = readNumber((((startDate.year == endDate.year) && (startDate.month == endDate.month))
                                  ? startDate.day
                                  : 1),
                             countDaysInMonth(endDate.year, endDate.month));
    return endDate;
}
stTwoDates readPeriod()
{
    stTwoDates periodDate;
    periodDate.startDate = getStartPeriodDate();
    periodDate.endDate = getEndPeriodDate(periodDate.startDate);
    return periodDate;
}
int differenceBetweenTwoDates(const Date date1, const Date date2)
{
    return countDaysInDate(date1.year, date2) -
           countDaysInDate(date1.year, date1);
}
int main()
{
    stTwoDates period = readPeriod();
    cout << "==========================================\n";
    int difference = differenceBetweenTwoDates(period.startDate, period.endDate);
    cout << "\nDifference Between Both Is   = " << difference
         << "\nDifference Including End Day = " << difference + 1 << '\n';
    return 0;
}