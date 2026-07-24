#include <iostream>
using namespace std;
float readNumber()
{
    float number;
    cout << "\n-Function For Abs-\n\n"
         << "Enter Number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < -10000 || 10000 < number)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Numeric Value [-10,000, 10,000]\n"
             << "Enter Number: ";
        cin >> number;
    }
    return number;
}
float myAbsFunction(float number)
{
    if (number < 0)
        number *= -1;
    return number;
}
void printResult(float numberAbs, float number)
{
    cout << "\n=============================\n"
         << "My abs Result : " << numberAbs << '\n'
         << "C++ abs Result: " << abs(number) << '\n';
}
int main()
{
    float number = readNumber();
    printResult(myAbsFunction(number), number);
    return 0;
}