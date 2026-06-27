#include <iostream>
#include <string>
using namespace std;
void readAge()
{
    short int age;
    cout << "Enter Your Age: ";
    cin >> age;
    while (cin.fail() || age < 18 || age > 45)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\"Invlid Age\", Enter A Valid Age"
             << "(18 <= Age <= 45)\n"
             << "Enter The Age: ";
        cin >> age;
    }
}
void printvallidation()
{
    cout << "=======================\n"
         << "Valid Age";
}
int main()
{
    readAge();
    printvallidation();
    return 0;
}