#include <iostream>
#include <limits>
using namespace std;
const string monthsArray[12] = {"Jan", "Feb", "Mar", "Apr",
                                "May", "Jun", "Jul", "Aug",
                                "Sep", "Oct", "Nov", "Dec"};
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
void printDaysNumInMonth(short currentDayOrder, const short daysInMonth)
{
    short day = 1;
    for (short i = 1; i <= daysInMonth + 6; i++)
    {
        if (day <= daysInMonth && currentDayOrder + 1 == i)
        {
            cout << day << "\t";
            if (i % 7 == 0 && day != daysInMonth)
                cout << '\n';
            currentDayOrder++;
            day++;
        }
        else
            cout << "\t";
    }
}
int main()
{
    cout << "=================================================\n"
         << "                Month Calender\n"
         << "=================================================\n"
         << "Enter Year To Check  : ";
    short year = readNumber(1, 32600);
    cout << "\nEnter Month To Check : ";
    short month = readNumber(1, 12);
    bool leapYear = isLeapYear(year);
    short daysInMonth = countDaysInMonth(leapYear, month);
    short currentDayOrder = dayOrderInWeek(1, month, year);
    cout << "\n======================= " << monthsArray[month - 1] << " =======================\n"
         << "Sun" << "\tMon" << "\tTue" << "\tWed" << "\tThu" << "\tFri" << "\tSat\n";
    printDaysNumInMonth(currentDayOrder, daysInMonth);
    cout << "\n===================================================";
    return 0;
}