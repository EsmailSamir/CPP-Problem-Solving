#include <iostream>
#include <limits>
using namespace std;
struct stDate
{
    short year;
    short month;
    short day;
};
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
short readNumber()
{
    short Number = 0;
    cin >> Number;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Number: ";
        cin >> Number;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return Number;
}
stDate getDate()
{
    stDate userDate;
    cout << "Enter Date:\n"
         << "Enter Year To Check  : ";
    userDate.year = readNumber();
    cout << "Enter Month To Check : ";
    userDate.month = readNumber();
    cout << "Enter Day To Check   : ";
    userDate.day = readNumber();
    return userDate;
}
bool checkDate(const stDate userDate)
{

    return !(userDate.year < 1 || userDate.month < 1 ||
             userDate.month > 12 || userDate.day < 1 ||
             userDate.day > countDaysInMonth(userDate.year, userDate.month));
}
int main()
{
    cout << (checkDate(getDate())
                 ? "Yes, It Is"
                 : "No, It Is Not")
         << " A Valid Date.";
    return 0;
}