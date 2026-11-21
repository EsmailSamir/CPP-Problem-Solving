#include <iostream>
using namespace std;

class clsPersons
{
private:
    short _Id = 21720;
    string _FirstName;
    string _LastName;

public:
    short Id()
    {
        return _Id;
    }
    void setFirstName(string firstName)
    {
        _FirstName = firstName;
    }
    void setLastName(string lastName)
    {
        _LastName = lastName;
    }
    string FirstName()
    {
        return _FirstName;
    }
    string LastName()
    {
        return _LastName;
    }

    string FullName()
    {
        return _FirstName + ' ' + _LastName;
    }
};

int main()
{

    clsPersons person1;
    person1.setFirstName("Esmail");
    person1.setLastName("Samir");
    cout << "First Name Is: " << person1.FirstName()
         << "\nLast Name Is : " << person1.LastName()
         << "\nPerson Id Is : " << person1.Id()
         << "\n\nFull Name Is : " << person1.FullName()
         << endl;

    return 0;
}