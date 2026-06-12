#include <iostream>
#include <string>
using namespace std;
string readName()
{
    string name;
    cout << "\nEnter Your Name: ";
    getline(cin, name);
    return name;
}
void printName(string yourName)
{
    cout << "\n=================================\n"
         << "Hello, " << yourName << ".\n";
}
int main()
{
    string yourName = readName();
    printName(yourName);
    return 0;
}