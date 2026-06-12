#include <iostream>
using namespace std;
struct vehicle
{
    string model;
    short int year;
    string color;
};
struct owner
{
    string name;
    short int age;
    string adress;
    vehicle car;
};
int main()
{
    owner person;
    cout << "enter your name: ";
    cin >> person.name;
    cout << "enter your age: ";
    cin >> person.age;
    cout << "enter your adress: ";
    cin >> person.adress;
    cout << "enter your car model: ";
    cin >> person.car.model;
    cout << "enter your car year: ";
    cin >> person.car.year; 
    cout << "enter your car color: ";
    cin >> person.car.color;
    cout << "______________________________\n"
         << "your name is      : " << person.name << "\n"
         << "and your age is   : " << person.age << "\n"
         << "and your adress is: " << person.adress << "\n"
         << "and your car model: " << person.car.model << "\n"
         << "and made in       : " << person.car.year << "\n"
         << "and his color is  : " << person.car.color << "\n"
         << "welcome in new struct project.";
    return 0;
}