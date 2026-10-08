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
short countDaysInYear(const short year)
{
    return isLeapYear(year) ? 366 : 365;
}
short dayOrderInYear(const Date &currentDate)
{
    short totalDays = 0;
    for (short i = 1; i < currentDate.month; i++)
    {
        totalDays += countDaysInMonth(currentDate.year, i);
    }
    return totalDays + currentDate.day;
}
int countDaysInDate(const short startYear, const Date &date)
{
    int daysInYear = 0;
    for (short i = startYear; i < date.year; i++)
    {
        daysInYear += countDaysInYear(i);
    }
    return daysInYear + dayOrderInYear(date);
}
int differenceBetweenTwoDates(const Date date1, const Date date2)
{
    return countDaysInDate(date1.year, date2) -
           countDaysInDate(date1.year, date1);
}
short countOverlapDays(const TwoDates period1, const TwoDates period2)
{
    if (!isOverlap(period1, period2))
        return 0;
    TwoDates theFirstStartPeriod = period1, theSecondStartPeriod = period2,
             theFirstEndPeriod = period1, theSecondEndPeriod = period2;
    if (compareTwoDates(period1.startDate, period2.startDate) == enResult::After)
    {
        theFirstStartPeriod = period2;
        theSecondStartPeriod = period1;
    }
    if (compareTwoDates(period1.endDate, period2.endDate) == enResult::After)
    {
        theFirstEndPeriod = period2;
        theSecondEndPeriod = period1;
    }
    return differenceBetweenTwoDates(theSecondStartPeriod.startDate, theFirstEndPeriod.endDate);
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
         << " Overlap Periods.\n"
         << "And Overlap Days = "
         << countOverlapDays(arrTwoPeriods[0], arrTwoPeriods[1]);
    return 0;
}