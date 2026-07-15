#include <iostream>
using namespace std;
void readNumber(float &base, float &exponent)
{
    cout << "\nEnter The Base Number: ";
    cin >> base;
    cout << "Enter Exponent Number: ";
    cin >> exponent;
    while (cin.fail() || exponent != (short int)exponent || exponent < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nEnter The Base Number: ";
        cin >> base;
        cout << "Exponent Can Not Be A Float value"
             << "Enter Exponent Number: ";
        cin >> exponent;
    }
}
double powNumber(const float &base, const float &exponent)
{
    double result = 1;
    for (short int i = 1; i <= exponent; i++)
    {
        result = base * result;
    }
    return result;
}
void printPow(const float &base, const float &exponent, const double &result)
{
    cout << "\n========================================\n"
         << "The Base " << base << " for Exponent " << exponent
         << " = " << result << '\n';
}
int main()
{
    float base, exponent;
    readNumber(base, exponent);
    printPow(base, exponent, powNumber(base, exponent));
    return 0;
}