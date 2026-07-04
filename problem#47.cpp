#include <iostream>
using namespace std;
void readAll(long &loanAmount, short int &monthlyPayment)
{
    cout << "Enter Loan Amount: ";
    cin >> loanAmount;
    while (cin.fail() || loanAmount <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value > 0\n"
             << "Enter Loan Amount: ";
        cin >> loanAmount;
    }
    cout << "Enter Monthly Payment: ";
    cin >> monthlyPayment;
    while (cin.fail() || monthlyPayment <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value > 0\n"
             << "Enter Monthly Payment: ";
        cin >> monthlyPayment;
    }
}
void calcSettle(const long loanAmount, const short int monthlyPayment,
                short int &remainder, short int &settle)
{
    settle = loanAmount / monthlyPayment;
    remainder = (loanAmount % monthlyPayment) * 30 / monthlyPayment;
}
void printSettle(const short int settle, const short int remainder)
{
    cout << "==============================\n"
         << settle << " Months And " << remainder << " Days.";
}
int main()
{
    long loanAmount;
    short int monthlyPayment, remainder, settle;
    readAll(loanAmount, monthlyPayment);
    calcSettle(loanAmount, monthlyPayment, remainder, settle);
    printSettle(settle, remainder);
    return 0;
}