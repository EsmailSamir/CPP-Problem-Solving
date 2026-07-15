#include <iostream>
using namespace std;
short int age()
{
    short int yourAge;
    cout << "\nEnter your age: ";
    cin >> yourAge;
    return yourAge;
}
short int license()
{
    short int haveLicense;
    cout << "\nHave a driver license ((1)Yes, (2)No): ";
    cin >> haveLicense;
    return haveLicense;
}
void decision(short int userAge, short int userHaveLicense)
{
    cout << "\n===============================\n";
    if (userAge > 21 && userHaveLicense == 1)
    {
        cout << "Hired\n";
    }
    else
        cout << "Rejected\n";
}
int main()
{
    decision( age(), license());
    return 0;
}