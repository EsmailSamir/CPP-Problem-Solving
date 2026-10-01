#include <iostream>
#include <limits>
using namespace std;
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
    cout << "\nNumber Of Days From Begining Year = " << dayOrder << '\n';
    return 0;
}