#include <iostream>
using namespace std;
void readAll(double &loanAmount, short int &months)
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
    cout << "Enter How Many Month: ";
    cin >> months;
    while (cin.fail() || months <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Positive Numeric Value > 0\n"
             << "Enter How Many Month: ";
        cin >> months;
    }
}
double calcMonthlyPayment(const double loanAmount, const short int months)
{
    return loanAmount / months;
}
void printMonthlyPayment(const double monthlyPayment)
{
    cout << "==============================\n"
         << monthlyPayment << " Every Month";
}
int main()
{
    double loanAmount;
    short int months;
    readAll(loanAmount, months);
    printMonthlyPayment(calcMonthlyPayment(loanAmount, months));
    return 0;
}