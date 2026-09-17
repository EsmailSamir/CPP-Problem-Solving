#include <iostream>
#include <limits>
using namespace std;
long readYear(const long from, const long to)
{
    long year;
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
bool isLeapYear(const long year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
int main()
{
    cout << "=================================================\n"
         << "                 Chick Leap Year"
         << "\n=================================================\n";
    if (isLeapYear(readYear(1, 1215752191)))
        cout << "Yes, Is Leap Year.\n";
    else
        cout << "No, Is Not Leap Year.\n";
    return 0;
}