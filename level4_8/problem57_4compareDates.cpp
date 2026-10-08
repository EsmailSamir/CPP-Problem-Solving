#include <iostream>
#include <limits>
using namespace std;
struct Date
{
    short year;
    short month;
    short day;
};
enum enResult
{
    Before = -1,
    Equal = 0,
    After = 1
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
enResult compareTwoDates(const Date date1, const Date date2)
{
    if (date1.year > date2.year ||
        (date1.year == date2.year &&
         (date1.month > date2.month ||
          date1.month == date2.month && date1.day > date2.day)))
        return enResult::After;
    else if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
        return enResult::Equal;
    else
        return enResult::Before;
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
    enResult resultCompare = compareTwoDates(arrDates[0], arrDates[1]);
    cout << "=================================\n"
         << "Result Compare: "
         << (resultCompare == enResult::After
                 ? "1 After"
             : resultCompare == enResult::Equal ? "0 Equal"
                                                : "-1 Before");
    return 0;
}