#include <iostream>
#include <cmath>
using namespace std;
float readNumber()
{
    float number;
    cout << "\n-Function For Ceil-\n\n"
         << "Enter A Float Number: ";
    cin >> number;
    while (cin.fail() || number < -10000 || 10000 < number)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Numeric Value [-10,000, 10,000]\n"
             << "Enter A Float Number: ";
        cin >> number;
    }
    return number;
}
int myCeilFunction(float number)
{
    if (number >= 0)
    {
        if (int(number) == number)
            return int(number);
        else
            return int(number) + 1;
    }
    else
        return int(number);
}
void printResult(float numberCeil, float number)
{
    cout << "\n=============================\n"
         << "My Ceil Result : " << numberCeil << '\n'
         << "C++ Ceil Result: " << ceil(number) << '\n';
}
int main()
{
    float number = readNumber();
    printResult(myCeilFunction(number), number);
    return 0;
}