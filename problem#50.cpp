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
    cout << "Correct PIN,\n"
         << "Your Balance Is: 7500$";
}
int main()
{
    string pin;
    for (short int i = 2; i >= 0; i--)
    {
        readPIN(pin);
        if (testPin(pin))
        {
            printBalance();
            break;
        }
        else
        {
            if (i == 0)
            {
                cout << "Wrong PIN,\n"
                     << "Your Card Is Locked.\n";
                break;
            }
            else
            {
                cout << "Wrong PIN,\n"
                     << "You Have " << i << " Try...\n";
            }
        }
    }
    return 0;
}