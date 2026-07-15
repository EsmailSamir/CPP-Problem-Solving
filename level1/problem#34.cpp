#include <iostream>
using namespace std;
float readTotal()
{
    float total;
    cout << "Enter The total: ";
    cin >> total;
    while (cin.fail() || total < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value > 0\n"
             << "Enter The Total: ";
        cin >> total;
    }
    return total;
}
float calcCommission(float total)
{
    if (total > 1000000)
        return total * 0.01;
    else if (total > 500000)
        return total * 0.02;
    else if (total > 100000)
        return total * 0.03;
    else if (total > 50000)
        return total * 0.05;
    else
        return 0;
}
void printCommission(float commission)
{
    cout << "============================================\n"
         << "The Commission Of The total Is: " << commission;
}
int main()
{
    printCommission(calcCommission(readTotal()));
    return 0;
}