#include <iostream>
#include <string>
using namespace std;
struct fullName
{
    string firstName;
    string lastName;
};
fullName readFullName()
{
    fullName userFullName;
    cout << "Enter your first name: ";
    cin >> userFullName.firstName;
    cout << "Enter your last name : ";
    cin >> userFullName.lastName;
    return userFullName;
}
string conectFullName(fullName userFullName)
{
    string full_name = userFullName.firstName + " " + userFullName.lastName;
    return full_name;
}
void printFullName(fullName userFullName)
{
    cout << "Full Name Is: "
         << conectFullName(userFullName);
}
/*void FULL_NAME()
{
    string Full_Name;
    cout << "Enter Full Name: ";
    getline(cin, Full_Name);
    cout << "Full Name Is: "
         << Full_Name;
}*/
int main()
{
    printFullName(readFullName());
    /*FULL_NAME();*/
    return 0;
}