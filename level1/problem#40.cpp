#include <iostream>
using namespace std;
float readBillValue()
{
    float billValue;
    cout << "Enter Bill Value: ";
    cin >> billValue;
    while (cin.fail() || billValue <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Numeric Value > 0: ";
        cin >> billValue;
    }
    return billValue;
}
float calcFees(const float billValue)
{
    const float fees = 1.1f;
    return billValue * fees;
}
float calcTax(const float afterFees)
{
    const float Tax = 1.16f;
    return afterFees * Tax;
}
void printTotal(const float afterTax)
{
    cout << "=========================\n"
         << "Total Bill = " << afterTax;
}
int main()
{
    printTotal(calcTax(calcFees(readBillValue())));
    return 0;
}