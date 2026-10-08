#include <iostream>
#include <limits>
using namespace std;
struct Date
{
    short year;
    short month;
    short day;
};
struct TwoDates
{
    Date startDate;
    Date endDate;
};
enum enResult
{
    Before = -1,
    Equal = 0,
    After = 1
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
TwoDates readPeriod()
{
    TwoDates periodDate;
    periodDate.startDate = getStartPeriodDate();
    periodDate.endDate = getEndPeriodDate(periodDate.startDate);
    return periodDate;
}
enResult compareTwoDates(const Date date1, const Date date2)
{
    if (date1.year > date2.year ||
        (date1.year == date2.year &&
         (date1.month > date2.month ||
          date1.month == date2.month && date1.day > date2.day)))
        return enResult::After;
    else if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
        return enResult::Equal;
    else
        return enResult::Before;
}
bool isOverlap(const TwoDates period1, const TwoDates period2)
{
    return (compareTwoDates(period1.startDate, period2.endDate) != enResult::After) &&
           (compareTwoDates(period2.startDate, period1.endDate) != enResult::After);
}
int main()
{
    TwoDates arrTwoPeriods[2];
    for (short i = 0; i < 2; i++)
    {
        cout << "Enter Period  [" << i + 1 << "] :\n\n";
        arrTwoPeriods[i] = readPeriod();
        cout << "============================\n";
    }
    cout << (isOverlap(arrTwoPeriods[0], arrTwoPeriods[1])
                 ? "Yes, It Is"
                 : "No, It Is Not")
         << " Overlap Periods.";
    return 0;
}