#include <iostream>
using namespace std;
void readTotal(short int &penny, short int &nickel, short int &dime, short int &quarter, short int &dollar)
{
    cout << "Enter Pennies: ";
    cin >> penny;
    while (cin.fail() || penny < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n"
             << "Enter Pennies: ";
        cin >> penny;
    }
    cout << "Enter Nickels: ";
    cin >> nickel;
    while (cin.fail() || nickel < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter Nickels: ";
        cin >> nickel;
    }
    cout << "Enter Dime: ";
    cin >> dime;
    while (cin.fail() || dime < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter Dime: ";
        cin >> dime;
    }
    cout << "Enter Quarters: ";
    cin >> quarter;
    while (cin.fail() || quarter < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter Quarters: ";
        cin >> quarter;
    }
    cout << "Enter Dollars: ";
    cin >> dollar;
    while (cin.fail() || dollar < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n"
             << "Enter Dollars: ";
        cin >> dollar;
    }
}
int proccAll(const short int &penny, const short int &nickel, const short int &dime, const short int &quarter, const short int &dollar)
{
    return penny + nickel * 5 + dime * 10 + quarter * 25 + dollar * 100;
}
void printDollars(const int &pennies)
{
    cout << "You Have " << pennies << " pennies.\n"
         << "And You Have " << pennies / 100.0 << " Dollars.";
}
int main()
{
    short int penny, nickel, dime, quarter, dollar;
    readTotal(penny, nickel, dime, quarter, dollar);
    printDollars(proccAll(penny, nickel, dime, quarter, dollar));
    return 0;
}