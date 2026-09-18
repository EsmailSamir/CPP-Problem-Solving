#include <iostream>
#include <limits>
using namespace std;
const string dayArray[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
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
short dayOrderInWeek(const short dayNum, const short month, const short year)
{
    // Sakamoto's Algorithm - Calculates Day
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;
    return (dayNum + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
int main()
{
    cout << "=================================================\n"
         << "           Count Order Day In Week"
         << "\n================================================="
         << "\nEnter Year To Check  : ";
    short year = readNumber(1, 32600);
    cout << "\nEnter Month To Check : ";
    short month = readNumber(1, 12);
    bool leapYear = isLeapYear(year);
    short daysInMonth = countDaysInMonth(leapYear, month);
    cout << "\nEnter Day To Check   : ";
    short dayNum = readNumber(1, daysInMonth);
    short dayOrder = dayOrderInWeek(dayNum, month, year);
    cout << "\n================================\n";
    if (leapYear)
        cout << "Yes, It Is A Leap Year.\n";
    else
        cout << "No, It Is Not A Leap Year.\n";
    cout << "\nDate      : " << year << "/" << month << "/" << dayNum
         << "\nDay Order : " << dayOrder
         << "\nDay Name  : " << dayArray[dayOrder] << '\n';
    return 0;
}