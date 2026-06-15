#include <iostream>
#include <string>
using namespace std;
short int readAge()
{
    short int age;
    cout << "Enter Your age: ";
    cin >> age;
    while (cin.fail() || age <= 0 || age > 120)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric (Value > 0)\n"
             << "Enter The age: ";
        cin >> age;
    }
    return age;
}
bool proccAge(short int age)
{
    return (age >= 18 && age <= 45);
}
void printvallidation(bool validatation)
{
    cout << "=================================\n";
    if (validatation)
    {
        cout << "Valid Age";
    }
    else
        cout << "Invalid Age";
}
int main()
{
    printvallidation(proccAge(readAge()));
    return 0;
}