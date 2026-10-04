#include <iostream>
#include <limits>
#include <ctime>
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
short countDaysInYear(const short year)
{
    return isLeapYear(year) ? 366 : 365;
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
int countDaysInDate(const short startYear, const Date date)
{
    int daysInYear = 0;
    for (short i = startYear; i < date.year; i++)
    {
        daysInYear += countDaysInYear(i);
    }
    return daysInYear + DayOrderInYear(date);
}
int differenceBetweenTwoDates(const Date currentDate, const Date userBirthDate)
{ // Just For Birthday.
    return countDaysInDate(userBirthDate.year, currentDate) -
           countDaysInDate(userBirthDate.year, userBirthDate);
}
Date getCurrentDate()
{
    Date currentDate;
    // 1. الحصول على الوقت الحالي بالثواني من النظام
    time_t now = time(0);
    // 2. تحويل الثواني إلى هيكل (Struct tm) عشان نقدر نقراه
    tm *ltm = localtime(&now);
    // 3. استخراج السنة، الشهر، واليوم وحفظهم في متغيرات
    // بنجمع 1900 لأن الخاصية tm_year بتبدأ العد من سنة 1900
    currentDate.year = 1900 + ltm->tm_year;
    // بنجمع 1 لأن الخاصية tm_mon بتبدأ العد من 0 (يعني شهر يناير رقمه 0)
    currentDate.month = 1 + ltm->tm_mon;
    // اليوم مش بيحتاج تعديل
    currentDate.day = ltm->tm_mday;
    return currentDate;
}
int main()
{
    Date userBirthDate, currentDate = getCurrentDate();
    cout << "Enter Date Of Birth :\n"
         << "Enter Year  : ";
    userBirthDate.year = readNumber(1, currentDate.year);
    cout << "Enter Month : ";
    userBirthDate.month = readNumber(1, (userBirthDate.year == currentDate.year ? currentDate.month : 12));
    cout << "Enter Day   : ";
    userBirthDate.day = readNumber(1, (userBirthDate.year == currentDate.year &&
                                               userBirthDate.month == currentDate.month
                                           ? currentDate.day
                                           : countDaysInMonth(userBirthDate.year, userBirthDate.month)));
    cout << "============================\n"
         << "Your Age By Days = " << differenceBetweenTwoDates(currentDate, userBirthDate);
    return 0;
}