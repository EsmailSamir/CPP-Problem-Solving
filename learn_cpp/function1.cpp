#include <iostream>
using namespace std;
string func1()
{
    string fullname;
    cout << "enter yuor full name: ";
    getline(cin, fullname);
    return fullname;
}
short int age()
{
    short int born;
    cout << "enter year of born: ";
    cin >> born;
    return born;
}
short int will(short int myAge)
{
    return (myAge + 5);
} 
int main()
{
    string fullname = func1();
    short int born = age();
    short int years = (2026 - born);
    short int willAge = will(years);
    cout << "hello, " << fullname << "\n"
         << "you are " << years << " years old." << "\n"
         << "you will be " << willAge
         << " after 5 years.";
    return 0;
}