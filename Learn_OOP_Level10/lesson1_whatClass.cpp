#include <iostream>
using namespace std;

class clsPersons
{
private:
    int x;

protected:
public:
    string firstName;
    string lastName;
    string fullName()
    {
        return firstName + ' ' + lastName;
    }
};

int main()
{

    clsPersons person1;
    person1.firstName = "Esmail";
    person1.lastName = "Samir";
    cout << person1.fullName() << endl;

    return 0;
}