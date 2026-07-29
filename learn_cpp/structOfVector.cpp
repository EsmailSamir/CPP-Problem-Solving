#include <iostream>
#include <vector>
using namespace std;
struct stPersonInfo
{
    string name;
    string jop;
    string salary;
};
void readNumber(vector<stPersonInfo> &vPerson)
{
    stPersonInfo person;
    bool more;
    do
    {
        cout << "Enter First Name: ";
        getline(cin, person.name);
        cout << "Enter jop: ";
        getline(cin, person.jop);
        cout << "Enter salary: ";
        getline(cin, person.salary);
        vPerson.push_back(person);
        cout << "Do You Want To Add More?\n"
             << "(1)Yes, (0)No : ";
        cin >> more;
        while (cin.fail() || cin.peek() != '\n' || more < 0 || 1 < more)
        {
            cin.clear();
            cin.ignore(1000000000, '\n');
            cout << "\nEnter A Positive Numeric Value[0, 1]:\n"
                 << "(1)Yes, (0)No : ";
            cin >> more;
        }
        cin.ignore(1000000000, '\n');
    } while (more);
}
void printVector(const vector<stPersonInfo> &vPerson)
{
    for (const stPersonInfo &person : vPerson)
    {
        cout << '\n'
             << person.name << '\n'
             << person.jop << '\n'
             << person.salary << "\n\n";
    }
}
int main()
{
    vector<stPersonInfo> vPerson;
    readNumber(vPerson);
    printVector(vPerson);
    return 0;
}