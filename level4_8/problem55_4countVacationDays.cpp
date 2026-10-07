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
Date calculateVacationReturnDate(Date startDate, short vacationDays)
{
    Date returnDate = startDate;
    short dayOrder = dayOrderInWeek(returnDate);
    while (vacationDays > 0)
    {
        if (dayOrder == 5 || dayOrder == 6)
        {
            returnDate = addDaysToDate(returnDate, 7 - dayOrder);
            dayOrder = 0;
        }
        else if (dayOrder == 0 && vacationDays >= 5)
        {
            short speedJump = (vacationDays / 5);
            vacationDays -= (5 * speedJump);
            returnDate = addDaysToDate(returnDate, (7 * speedJump));
            dayOrder = 0;
        }
        else
        {
            vacationDays--;
            returnDate = addDaysToDate(returnDate, 1);
            dayOrder++;
        }
    }
    if (dayOrder == 5 || dayOrder == 6)
        returnDate = addDaysToDate(returnDate, 7 - dayOrder);
    return returnDate;
}
void printDate(const Date &currentDate)
{
    cout << currentDate.year << "/" << currentDate.month << "/" << currentDate.day;
}
int main()
{
    Date startDate = getStartVacationDate();
    cout << "\nEnter Vacation Days : ";
    short vacationDays = readNumber(1, 32600);
    Date returnDate = calculateVacationReturnDate(startDate, vacationDays);
    cout << "\n===========================================\n"
         << "Vacation Start From : " << dayArray[dayOrderInWeek(startDate)] << " , ";
    printDate(startDate);
    cout << "\nReturn Date         : " << dayArray[dayOrderInWeek(returnDate)] << " , ";
    printDate(returnDate);
    return 0;
}