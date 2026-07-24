#include <iostream>
#include <cmath>
using namespace std;
int readNumber()
{
    int number;
    cout << "\n-Function For Sqrt-\n\n"
         << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || number < 0 || 10000 < number)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value [0, 10,000]\n"
             << "Enter A Number: ";
        cin >> number;
    }
    return number;
}
float mySqrtFunction(int number)
{
    return pow(number, 0.5);
}
void printResult(float numberSqrt, int number)
{
    cout << "\n=============================\n"
         << "My Sqrt Result : " << numberSqrt << '\n'
         << "C++ Sqrt Result: " << sqrt(number) << '\n';
}
int main()
{
    int number = readNumber();
    printResult(mySqrtFunction(number), number);
    return 0;
}