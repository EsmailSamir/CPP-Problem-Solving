#include <iostream>
using namespace std;
struct stPersons
{
    string name;
    short salary;
};

int main()
{
    stPersons employe, *pointer;
    pointer = &employe;
    employe.name = "som3a";
    employe.salary = 10000;
    cout << employe.name << '\n'
         << employe.salary << '\n'
         << "by Pointer " << '\n'
         << pointer->name << '\n'
         << pointer->salary;
    return 0;
}