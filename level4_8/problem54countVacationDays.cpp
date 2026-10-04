#include <iostream>
#include <limits>
using namespace std;
const string dayArray[7] =
    {"Sunday", "Monday", "Tuesday", "Wednesday",
     "Thursday", "Friday", "Saturday"};
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
short dayOrderInWeek(const Date &currentDate)
{
    // Sakamoto's Algorithm - Calculates Day
    short a = (14 - currentDate.month) / 12;
    short y = currentDate.year - a;
    short m = currentDate.month + (12 * a) - 2;
    return (currentDate.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
Date getStartVacationDate()
{
    Date startDate;
    cout << "Start Vacation\n\n"
         << "Enter Year To Check  : ";
    startDate.year = readNumber(1, 32600);
    cout << "Enter Month To Check : ";
    startDate.month = readNumber(1, 12);
    cout << "Enter Day To Check   : ";
    startDate.day = readNumber(1, countDaysInMonth(startDate.year, startDate.month));
    return startDate;
}
Date getEndVacationDate(const Date &startDate)
{
    Date endDate;
    cout << "\n\nEnd Vacation\n\n"
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
int differenceBetweenTwoDates(const Date &startDate, const Date &endDate)
{
    return countDaysInDate(startDate.year, endDate) -
           countDaysInDate(startDate.year, startDate);
}
Date addDaysToDate(Date newDate, short daysToAdd)
{
    while (daysToAdd > 0)
    {
        short daysInMonth = countDaysInMonth(newDate.year, newDate.month);
        short remainDaysInYear = 0;
        for (short i = newDate.month; i <= 12; i++)
        {
            remainDaysInYear += countDaysInMonth(newDate.year, i);
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
short countWeekends(Date startDate, const short differenceTwoDates)
{
    short count = 0, i = 0,
          orderDay = dayOrderInWeek(startDate);
    for (; i < differenceTwoDates;)
    {
        if (orderDay != 6)
        {
            if (orderDay == 5)
                count++;
            startDate = addDaysToDate(startDate, 1);
            i++;
            orderDay++;
        }
        else
        {
            count++;
            startDate = addDaysToDate(startDate, 6);
            i += 6;
            orderDay = 5;
        }
    }
    return count;
}
void printDate(const Date &currentDate)
{
    cout << currentDate.year << "/" << currentDate.month << "/" << currentDate.day;
}
int main()
{
    Date startDate = getStartVacationDate();
    Date endDate = getEndVacationDate(startDate);
    int difference = differenceBetweenTwoDates(startDate, endDate);
    cout << "===========================================\n"
         << "Vacation Start From : " << dayArray[dayOrderInWeek(startDate)] << " , ";
    printDate(startDate);
    cout << "\nVacation End To     : " << dayArray[dayOrderInWeek(endDate)] << " , ";
    printDate(endDate);
    cout << "\n\nDifference Between Both Is   = " << difference
         << "\nDifference Including End Day = ";
    difference++;
    cout << difference
         << "\nVacation Actual Days Without Weekends = "
         << (difference - countWeekends(startDate, difference));
    return 0;
}