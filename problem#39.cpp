#include <iostream>
using namespace std;
void readAll(float &totalBill, float &cashPaid)
{

    cout << "Enter Total Bill: ";
    cin >> totalBill;
    while (cin.fail() || totalBill <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Numeric Value > 0: ";
        cin >> totalBill;
    }
    cout << "Enter Cash Paid : ";
    cin >> cashPaid;
    while (cin.fail() || cashPaid < totalBill)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Numeric Value > " << totalBill << " : ";
        cin >> cashPaid;
    }
}
float calculateChange(const float &totalBill, const float &cashPaid)
{
    return cashPaid - totalBill;
}
void printChange(const float change)
{
    cout << "==============================\n"
         << "The Change =  " << change;
}
int main()
{
    float totalBill, cashPaid;
    readAll(totalBill, cashPaid);
    printChange(calculateChange(totalBill, cashPaid));
    return 0;
}