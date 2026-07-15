#include <iostream>
using namespace std;
void readPIN(string &pin)
{
    cout << "\nEnter Your PIN: ";
    cin >> pin;
}
bool testPin(const string &pin)
{
    return (pin == "1234");
}
void printBalance()
{
    cout << "\nCorrect PIN,\n"
         << "Your Balance Is: 7500$\n";
}
int main()
{
    string pin;
    while (true)
    {
        readPIN(pin);
        if (testPin(pin))
        {
            printBalance();
            break;
        }
        else
            cout << "Wrong PIN, Try Again...\n";
    }
    return 0;
}