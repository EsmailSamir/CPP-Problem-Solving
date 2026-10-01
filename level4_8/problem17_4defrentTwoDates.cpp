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
Date getBiggestDate(const Date date1, const Date date2)
{
    return (date1.year > date2.year ? date1 : (date1.year < date2.year ? date2 : (date1.month > date2.month ? date1 : (date1.month < date2.month ? date2 : (date1.day > date2.day ? date1 : date2)))));
}
Date getSmallestDate(const Date date1, const Date date2)
{
    return (date1.year < date2.year ? date1 : (date1.year > date2.year ? date2 : (date1.month < date2.month ? date1 : (date1.month > date2.month ? date2 : (date1.day < date2.day ? date1 : date2)))));
}
short countDaysInYear(const short Year)
{
    return isLeapYear(Year) ? 366 : 365;
}
short DayOrderInYear(const Date currentDate)
{
    short totalDays = 0;
    for (short i = 1; i < currentDate.month; i++)
    {
        totalDays += countDaysInMonth(isLeapYear(currentDate.year), i);
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
int differenceBetweenTwoDates(const Date date1, const Date date2)
{
    Date smallestDate = getSmallestDate(date1, date2);
    return countDaysInDate(smallestDate.year, getBiggestDate(date1, date2)) - countDaysInDate(smallestDate.year, smallestDate);
}
int main()
{
    Date twoDatesToCompare[2];
    for (short i = 0; i < 2; i++)
    {
        cout << "\nEnter Date [" << i + 1 << "] :\n\n"
             << "Enter Year [" << i + 1 << "] To Check  : ";
        twoDatesToCompare[i].year = readNumber(1, 32600);
        bool leapYear = isLeapYear(twoDatesToCompare[i].year);
        cout << "Enter Month [" << i + 1 << "] To Check : ";
        twoDatesToCompare[i].month = readNumber(1, 12);
        cout << "Enter Day [" << i + 1 << "] To Check   : ";
        twoDatesToCompare[i].day =
            readNumber(1, countDaysInMonth(leapYear, twoDatesToCompare[i].month));
        cout << "============================\n";
    }
    Date BiggestDate = getBiggestDate(twoDatesToCompare[0], twoDatesToCompare[1]);
    int difference = differenceBetweenTwoDates(twoDatesToCompare[0], twoDatesToCompare[1]);
    cout << "The Biggest Date Is      : "
         << BiggestDate.year << "/" << BiggestDate.month << "/" << BiggestDate.day
         << "\nDifference Between Both Is: "
         << difference << "\nDifference Including End Day = " << difference + 1;
    return 0;
}