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
bool isLastDayInMonth(const short day, const short daysInMonth)
{
    return day == daysInMonth;
}
bool isLastMonthInYear(const short month)
{
    return month == 12;
}
int main()
{
    Date userDate;
    cout << "Enter Year To Check  : ";
    userDate.year = readNumber(1, 32600);
    bool leapYear = isLeapYear(userDate.year);
    cout << "\nEnter Month To Check : ";
    userDate.month = readNumber(1, 12);
    cout << "\nEnter Day To Check   : ";
    short daysInMonth = countDaysInMonth(leapYear, userDate.month);
    userDate.day = readNumber(1, daysInMonth);
    cout << "=========================\n"
         << (isLastDayInMonth(userDate.day, daysInMonth) ? "Yes, It's Last Day In Month." : "No, It's Not Last Day In Month.")
         << '\n'
         << (isLastMonthInYear(userDate.month) ? "Yes, It's Last Month In Year." : "No, It's Not Last Month In Year.");
    return 0;
}