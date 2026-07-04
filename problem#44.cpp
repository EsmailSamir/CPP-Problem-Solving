#include <iostream>
using namespace std;
short int readNum()
{
    short int numOfDay;
    cout << "Enter Num Of Day: ";
    cin >> numOfDay;
    while (cin.fail() || numOfDay < 1 || numOfDay > 7)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value [1:7]\n"
             << "Enter Num Of Day: ";
        cin >> numOfDay;
    }
    return numOfDay;
}
void printDay(const short int numOfDay, const string days[])
{
    cout << "====================\n"
         << days[numOfDay - 1];
}
int main()
{
    const string days[] = {"Saturday", "Sunday", "Monday",
                             "Tuesday", "Wednesday", "Thursday", "Friday"};
    printDay(readNum(),days);
    return 0;
}
