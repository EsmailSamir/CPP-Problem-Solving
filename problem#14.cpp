#include <iostream>
using namespace std;
void readNumber(float &number1, float &number2)
{
    cout << "Enter Number A = ";
    cin >> number1;
    cout << "Enter Number B = ";
    cin >> number2;
}
void swabNumber(float &number1, float &number2)
{
    float temb = number1;
    number1 = number2;
    number2 = temb;
}
void printNumber(const float number1, const float number2)
{
    cout << "=====================\n"
         << "  A = " << number1 << '\n'
         << "  B = " << number2 << '\n';
}
int main()
{
    float number1, number2;
    readNumber(number1, number2);
    printNumber(number1, number2);
    swabNumber(number1, number2);
    printNumber(number1, number2);
    return 0;
}