#include <iostream>
#include <string>
using namespace std;
short int readAge()
{
    short int age;
    cout << "Enter Your Age: ";
    cin >> age;
    while (cin.fail() || age <= 0 || age > 100)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\"Invlid Age\", Enter A Valid Age"
             << "(18 <= Age <= 45)\n"
             << "Enter The Age: ";
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
    cout << "=======================\n";
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