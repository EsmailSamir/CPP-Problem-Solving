#include <iostream>
using namespace std;
struct id_person
{
    string first_name;
    string last_name;
    string phone_num;
    string age;
};
short int read_preson(id_person persons[])
{
    short int length;
    cout << "enter how many persons: ";
    cin >> length;
    for (short int i = 0; i < length; i++)
    {
        cout << "enter first name " << i + 1 << " : ";
        cin >> persons[i].first_name;
        cout << "enter last name  " << i + 1 << " : ";
        cin >> persons[i].last_name;
        cout << "enter phone numb " << i + 1 << " : ";
        cin >> persons[i].phone_num;
        cout << "enter age person " << i + 1 << " : ";
        cin >> persons[i].age;
        cin.ignore(1, '\n');
        cout << "***************************\n";
    }
    return length;
}
void print_info(id_person persons[], short int length)
{
    for (short int i = 0; i < length; i++)
    {
        cout << "\n\n"
             << "***************************\n"
             << "***************************\n"
             << "first name person " << i + 1 << " :"
             << persons[i].first_name << "\n"
             << "last name person  " << i + 1 << " :"
             << persons[i].last_name << "\n"
             << "phone num person  " << i + 1 << " :"
             << persons[i].phone_num << "\n"
             << "the age of person " << i + 1 << " :"
             << persons[i].age << "\n"
             << "***************************\n";
    }
}
int main()
{
    id_person persons[10];
    short int length = read_preson(persons);
    print_info(persons, length);
    return 0;
}