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
short DayOrderInYear(const Date currentDate)
{
    short totalDays = 0;
    for (short i = 1; i < currentDate.month; i++)
    {
        totalDays += countDaysInMonth(currentDate.year, i);
    }
    return totalDays + currentDate.day;
}
Date subtractDaysToDate(Date newDate, short daysToDecrease)
{
    while (daysToDecrease > 0)
    {
        if (daysToDecrease < newDate.day)
        {
            newDate.day -= daysToDecrease;
            break;
        }
        else if (daysToDecrease >= newDate.day && daysToDecrease < DayOrderInYear(newDate))
        {
            daysToDecrease -= newDate.day;
            newDate.month--;
            newDate.day = countDaysInMonth(newDate.year, newDate.month);
        }
        else
        {
            daysToDecrease -= DayOrderInYear(newDate);
            newDate.year--;
            newDate.month = 12;
            newDate.day = 31;
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
Date DecreaseMonthsToDate(Date newDate, const short numMonths)
{
    for (short i = numMonths; i >= 1; i--)
    {
        if (newDate.month > 1)
        {
            newDate.month--;
            short numDaysInMonth = countDaysInMonth(newDate.year, newDate.month);
            if (newDate.day > numDaysInMonth)
                newDate.day = numDaysInMonth;
        }
        else
        {
            newDate.year--;
            newDate.month = 12;
        }
    }
    return newDate;
}
Date DecreaseYearsToDate(Date newDate, const short numYears)
{
    newDate.year -= numYears;
    if (newDate.day == 29 && newDate.month == 2 && !isLeapYear(newDate.year))
        newDate.day = 28;
    return newDate;
}
int main()
{
    Date newDate = subtractDaysToDate(getDateFromUser(), 1);
    cout << "===================================================\n"
         << "[1]  Subtracting One Day Is           : ";
    printDate(newDate);
    cout << "[2]  Subtracting Ten Days Is          : ";
    newDate = subtractDaysToDate(newDate, 10);
    printDate(newDate);
    cout << "[3]  Subtracting One Week Is          : ";
    newDate = subtractDaysToDate(newDate, 7);
    printDate(newDate);
    cout << "[4]  Subtracting Ten Weeks Is         : ";
    newDate = subtractDaysToDate(newDate, 70);
    printDate(newDate);
    cout << "[5]  Subtracting One Month Is         : ";
    newDate = DecreaseMonthsToDate(newDate, 1);
    printDate(newDate);
    cout << "[6]  Subtracting Five Months Is       : ";
    newDate = DecreaseMonthsToDate(newDate, 5);
    printDate(newDate);
    cout << "[7]  Subtracting One Year Is          : ";
    newDate = DecreaseYearsToDate(newDate, 1);
    printDate(newDate);
    cout << "[8]  Subtracting Ten Years Is         : ";
    newDate = DecreaseYearsToDate(newDate, 10);
    printDate(newDate);
    cout << "[9]  Subtracting Ten Years (Faster)   : ";
    newDate = DecreaseYearsToDate(newDate, 10);
    printDate(newDate);
    cout << "[10] Subtracting One Decade Is        : ";
    newDate = DecreaseYearsToDate(newDate, 10);
    printDate(newDate);
    cout << "[11] Subtracting Ten Decades Is       : ";
    newDate = DecreaseYearsToDate(newDate, 100);
    printDate(newDate);
    cout << "[12] Subtracting Ten Decades (Faster) : ";
    newDate = DecreaseYearsToDate(newDate, 100);
    printDate(newDate);
    cout << "[13] Subtracting One Century Is       : ";
    newDate = DecreaseYearsToDate(newDate, 100);
    printDate(newDate);
    cout << "[14] Subtracting One Millennium Is    : ";
    newDate = DecreaseYearsToDate(newDate, 1000);
    printDate(newDate);
    return 0;
}