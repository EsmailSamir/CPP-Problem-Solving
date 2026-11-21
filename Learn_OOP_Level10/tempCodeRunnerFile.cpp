#include <iostream>
using namespace std;
class clsPerson
{
private:
    const string _Id = "21720";
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(const string &firstName,
              const string &lastName,
              const string &email, const string &phone)
    {
        _FirstName = firstName;
        _LastName = lastName;
        _Email = email;
        _Phone = phone;
    }
    string Id() const
    {
        return _Id;
    }
    void setFirstName(string &firstName)
    {
        _FirstName = firstName;
    }
    void setLastName(string &lastName)
    {
        _LastName = lastName;
    }
    string FirstName() const
    {
        return _FirstName;
    }
    string LastName() const
    {
        return _LastName;
    }
    string Email() const
    {
        return _Email;
    }
    string Phone() const
    {
        return _Phone;
    }
    string FullName() const
    {
        return _FirstName + ' ' + _LastName;
    }
    void SendEmail(const string &subject, const string &messageBody) const
    {
        cout << "\n------------------Email---------------------"
             << "\nThe Following Message Has Sent Successfully"
             << "\nTo Email: " << Email()
             << "\n\nSubject: " << subject
             << "\nBody: " << messageBody << '\n';
    }
    void SendSMS(const string &messageText) const
    {
        cout << "\n---------------SMS---------------------"
             << "\nThe Following SMS Has Sent Successfully"
             << "\nTo Phone: " << Phone()
             << "\n\nMessage: " << messageText << '\n';
    }
    void printInfo()
    {
        cout << "\t -- Info -- \n"
             << "\nID         : " << Id()
             << "\nFirst Name : " << FirstName()
             << "\nLast Name  : " << LastName()
             << "\nFull Name  : " << FullName()
             << "\nPhone      : " << Phone()
             << "\nEmail      : " << Email() << '\n';
    }
};

int main()
{
    clsPerson person1("Esmail", "Samir",
                      "ismaelsamer11@gmail.com", "01152735283");
    person1.printInfo();
    person1.SendEmail("Hi", "How Are You");
    person1.SendSMS("Hello I'm Here");
    return 0;
}