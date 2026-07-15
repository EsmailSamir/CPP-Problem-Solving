#include <iostream>
using namespace std;
struct idintifi
{
    string fullname;
    short int year_born;
    string phone;
};
void personRead(idintifi &person)
{
    cout << "enter your full name: ";
    getline(cin, person.fullname);
    cout << "enter year of born: ";
    cin >> person.year_born;
    cout << "enter your phone number: ";
    cin >> person.phone;
    cin.ignore(1, '\n');
}
void personBrint(const idintifi &person)
{
    cout << "------------------------------------------\n\n"
         << "welcome, " << person.fullname << "\n"
         << "your age is: " << (2026 - person.year_born) << "\n"
         << "your phone number is: " << person.phone << "\n"
         << "you will be " << 2026 - person.year_born + 4
         << "years old in 2030\n"
         << "------------------------------------------\n\n";
}
int main()
{
    idintifi person;
    personRead(person);
    personBrint(person);
    idintifi person2;
    personRead(person2);
    personBrint(person2);
    return 0;
}