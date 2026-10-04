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
short countDaysInYear(const short year)
{
    return isLeapYear(year) ? 366 : 365;
}
short countDaysInMonth(const short year, const short month)
{
    if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
        return month == 2 ? (isLeapYear(year) ? 29 : 28) : 30;
    return 31;
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
Date getDateFromUser()
{
    Date userDate;
    cout << "Enter Year To Check  : ";
    userDate.year = readNumber(1, 32600);
    cout << "Enter Month To Check : ";
    userDate.month = readNumber(1, 12);
    cout << "Enter Day To Check   : ";
    userDate.day = readNumber(1, countDaysInMonth(userDate.year, userDate.month));
    return userDate;
}
void printDate(const Date newDate)
{
    cout << newDate.year << "/" << newDate.month << "/" << newDate.day << "\n";
}
Date addMonthsToDate(Date newDate, const short numMonths)
{
    for (short i = 0; i < numMonths; i++)
    {
        if (newDate.month < 12)
        {
            newDate.month++;
            short numDaysInMonth = countDaysInMonth(newDate.year, newDate.month);
            if (newDate.day > numDaysInMonth)
                newDate.day = numDaysInMonth;
        }
        else
        {
            newDate.year++;
            newDate.month = 1;
        }
    }
    return newDate;
}
Date addYearsToDate(Date newDate, const short numYears)
{
    newDate.year += numYears;
    if (newDate.day == 29 && newDate.month == 2 && !isLeapYear(newDate.year))
        newDate.day = 28;
    return newDate;
}
Date addDecadeToDate(Date newDate, const short numTeensYears)
{
    return addYearsToDate(newDate, numTeensYears * 10);
}
Date addCenturyToDate(Date newDate, const short century)
{
    return addYearsToDate(newDate, century * 100);
}
int main()
{
    Date newDate = addDaysToDate(getDateFromUser(), 1);
    cout << "==========================================\n"
         << "[1]  Adding One Day Is              : ";
    printDate(newDate);
    cout << "[2]  Adding Ten Days Is             : ";
    newDate = addDaysToDate(newDate, 10);
    printDate(newDate);
    cout << "[3]  Adding One Week Is             : ";
    newDate = addDaysToDate(newDate, 7);
    printDate(newDate);
    cout << "[4]  Adding Ten Weeks Is            : ";
    newDate = addDaysToDate(newDate, 70);
    printDate(newDate);
    cout << "[5]  Adding One Month Is            : ";
    newDate = addMonthsToDate(newDate, 1);
    printDate(newDate);
    cout << "[6]  Adding Five Months Is          : ";
    newDate = addMonthsToDate(newDate, 5);
    printDate(newDate);
    cout << "[7]  Adding One Year Is             : ";
    newDate = addYearsToDate(newDate, 1);
    printDate(newDate);
    cout << "[8]  Adding Ten Years Is            : ";
    newDate = addYearsToDate(newDate, 10);
    printDate(newDate);
    cout << "[9]  Adding Ten Years Is (Faster)   : ";
    newDate = addDecadeToDate(newDate, 1);
    printDate(newDate);
    cout << "[10] Adding One Decade Is           : ";
    newDate = addDecadeToDate(newDate, 1);
    printDate(newDate);
    cout << "[11] Adding Ten Decades Is          : ";
    newDate = addDecadeToDate(newDate, 10);
    printDate(newDate);
    cout << "[12] Adding Ten Decades Is (Faster) : ";
    newDate = addCenturyToDate(newDate, 1);
    printDate(newDate);
    cout << "[13] Adding One Century Is          : ";
    newDate = addCenturyToDate(newDate, 1);
    printDate(newDate);
    cout << "[14] Adding One Millennium Is       : ";
    newDate = addCenturyToDate(newDate, 10);
    printDate(newDate);
    return 0;
}