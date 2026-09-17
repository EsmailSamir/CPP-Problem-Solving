#include <iostream>
#include <limits>
using namespace std;
const short hours = 24, minutes = 60, seconds = 60;
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
short countAllTimesInMonth(const short daysInMonth,
                           int &countMinutesInMonth,
                           int &countSecondsInMonth)
{
    short countHoursInMonth = daysInMonth * hours;
    countMinutesInMonth = countHoursInMonth * minutes;
    countSecondsInMonth = countMinutesInMonth * seconds;
    return countHoursInMonth;
}

int main()
{
    int countMinutesInMonth = 0, countSecondsInMonth = 0;
    short countHoursInMonth = 0, year = 0, month = 0, daysInMonth = 31;
    cout << "=================================================\n"
         << "       Count All Times By Year And Month"
         << "\n=================================================\n"
         << "Enter Year To Check: ";
    year = readNumber(1, 32600);
    cout << "\nEnter Month To Check: ";
    month = readNumber(1, 12);
    bool leapYear = isLeapYear(year);
    daysInMonth = countDaysInMonth(leapYear, month);
    countHoursInMonth = countAllTimesInMonth(daysInMonth,
                                             countMinutesInMonth,
                                             countSecondsInMonth);
    cout << "================================\n"
         << "In Year [" << year << "]:\n"
         << "And In Month [" << month << "]:\n\n";
    if (leapYear)
        cout << "Yes, It Is A Leap Year.\n";
    else
        cout << "No, It Is Not A Leap Year.\n";
    cout << "\nCount Of Days In Month    = " << daysInMonth << " Days"
         << "\nCount Of Hours In Month   = " << countHoursInMonth << " Hours"
         << "\nCount Of Minutes In Month = " << countMinutesInMonth << " Minutes"
         << "\nCount Of Seconds In Month = " << countSecondsInMonth << " Seconds\n";
    return 0;
}