#include <iostream>
#include <limits>
using namespace std;
const short hours = 24, minutes = 60, seconds = 60;
short readYear(const short from, const short to)
{
    short year;
    cout << "Enter Year: ";
    cin >> year;
    while (cin.fail() || cin.peek() != '\n' || year < from || to < year)
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
        cout << "Enter Year: ";
        cin >> year;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return year;
}
bool isLeapYear(const short year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
short countAllTimes(const bool leap, short &countHours, int &countMinutes, int &countSeconds)
{
    short days = leap ? 366 : 365;
    countHours = days * hours;
    countMinutes = countHours * minutes;
    countSeconds = countMinutes * seconds;
    return days;
}
int main()
{
    int countMinutes = 0, countSeconds = 0;
    short countHours = 0;
    cout << "=================================================\n"
         << "               Count All Times By Year"
         << "\n=================================================\n";
    short year = readYear(1, 32600);
    bool leap = isLeapYear(year);
    short days = countAllTimes(leap, countHours, countMinutes, countSeconds);
    cout << "\nIn Year [" << year << "]:\n\n";
    if (leap)
        cout << "Yes, It Is Leap Year.\n";
    else
        cout << "No, It Is Not Leap Year.\n";
    cout << "\nCount Of Days    = " << days
         << "\nCount Of Hours   = " << countHours
         << "\nCount Of Minutes = " << countMinutes
         << "\nCount Of Seconds = " << countSeconds << '\n';
    return 0;
}