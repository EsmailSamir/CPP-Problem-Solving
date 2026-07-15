#include <iostream>
#include <string>
using namespace std;
int main()
{
    string fullname, s1, s2;
    cout << "enter your full name: \n";
    cin.ignore(1, '\n');
    getline(cin, fullname);
    cout << "enter sting num 1: ";
    cin >> s1;
    cout << "enter sting num 2: ";
    cin >> s2;
    cout << "-----------------------------------\n"
         << "the lentgh of your name is: "
         << fullname.length() << "\n"
         << "your full name is: " << fullname << "\n"
         << "[" << fullname[11] << "]" << "\n"
         << s1 + s2 << "\n"
         << stoi(s1) + stoi(s2);
    return 0;
}