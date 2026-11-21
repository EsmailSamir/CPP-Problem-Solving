#include <iostream>
using namespace std;
class clsEmployee
{
private:
    const string _Id;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;
    string _Title;
    double _Salary;
    string _Department;

public:
    clsEmployee(const string &id, const string &firstName,
                const string &lastName, const string &email,
                const string &phone, const string &title,
                const double salary, const string &department)
        : _Id(id),
          _FirstName(firstName),
          _LastName(lastName),
          _Email(email),
          _Phone(phone),
          _Title(title),
          _Salary(salary),
          _Department(department)
    {
    }
    string Id() const
    {
        return _Id;
    }
    void SetFirstName(const string &firstName)
    {
        _FirstName = firstName;
    }
    void SetLastName(const string &lastName)
    {
        _LastName = lastName;
    }
    void SetEmail(const string &email)
    {
        _Email = email;
    }
    void SetPhone(const string &phone)
    {
        _Phone = phone;
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
        return FirstName() + ' ' + LastName();
    }
    void SetTitle(const string &title)
    {
        _Title = title;
    }
    string Title() const
    {
        return _Title;
    }
    void SetSalary(const double salary)
    {
        _Salary = salary;
    }
    double Salary() const
    {
        return _Salary;
    }
    void SetDepartment(const string &department)
    {
        _Department = department;
    }
    string Department() const
    {
        return _Department;
    }
    void SendEmail(const string &subject, const string &messageBody) const
    {
        cout << "\n------------------ Email ---------------------"
             << "\nThe Following Message Has Sent Successfully"
             << "\nTo Email: " << Email()
             << "\n\nSubject: " << subject
             << "\nBody: " << messageBody
             << "\n----------------------------------------------\n";
    }
    void SendSMS(const string &messageText) const
    {
        cout << "\n------------------- SMS ----------------------"
             << "\nThe Following SMS Has Sent Successfully"
             << "\nTo Phone: " << Phone()
             << "\n\nMessage: " << messageText
             << "\n----------------------------------------------\n";
    }
    void PrintInfo() const
    {
        cout << "\n------------------- Info ---------------------"
             << "\nID         : " << Id()
             << "\nFirst Name : " << FirstName()
             << "\nLast Name  : " << LastName()
             << "\nFull Name  : " << FullName()
             << "\nPhone      : " << Phone()
             << "\nEmail      : " << Email()
             << "\nTitle      : " << Title()
             << "\nSalary     : " << Salary()
             << "\nDepartment : " << Department()
             << "\n----------------------------------------------\n";
    }
};
int main()
{
    clsEmployee Employee1("217200", "Esmail", "Samir",
                          "ismaelsamer11@gmail.com", "01152735283",
                          "Software Engineer", 50000, "Engineering");
    Employee1.PrintInfo();
    Employee1.SendEmail("Hi", "How Are You");
    Employee1.SendSMS("Hello I'm Here");
    return 0;
}