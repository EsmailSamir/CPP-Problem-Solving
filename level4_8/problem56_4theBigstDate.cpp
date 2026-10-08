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
short countDaysInMonth(const short year, const short month)
{
    if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
        return month == 2 ? (isLeapYear(year) ? 29 : 28) : 30;
    return 31;
}
bool isDate1AfterDate2(const Date date1, const Date date2)
{
    return (date1.year > date2.year) ||
           (date1.year == date2.year && date1.month > date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day);
}
Date readDate()
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
int main()
{
    Date arrDates[2];
    for (short i = 0; i < 2; i++)
    {
        cout << "Enter Date  [" << i + 1 << "] :\n";
        arrDates[i] = readDate();
        cout << endl;
    }
    cout << "=================================\n"
         << (isDate1AfterDate2(arrDates[0], arrDates[1])
                 ? "Yes, Date1 Is"
                 : "No, Date1 Is Not")
         << " After Date2.";
    return 0;
}