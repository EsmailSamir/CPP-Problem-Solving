#include <iostream>
using namespace std;
int main()
{
    string name;
    cout << "enter your name: ";
    cin >> name;
    short int age;
    cout << "enter your age: ";
    cin >> age;
    cout << name << "\n"
         << age << "\n";
    cout << "your age after 5 years is " << age + 5 << " years.";
    return 0;
}