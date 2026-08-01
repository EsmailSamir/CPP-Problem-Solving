#include <iostream>
using namespace std;
struct stPersons
{
    string name;
    int salary;
};

int main()
{
    stPersons employe;
    void *pointer;
    pointer = &employe;
    employe.name = "som3a";
    employe.salary = 10000;
    cout << employe.name << '\n'
         << employe.salary << '\n'
         << "by Pointer " << '\n'
         << (static_cast<stPersons *>(pointer))->name << '\n'
         << (static_cast<stPersons *>(pointer))->salary;
    ;

    return 0;
}