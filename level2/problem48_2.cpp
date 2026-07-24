#include <iostream>
#include <cmath>
using namespace std;
float readNumber()
{
    float number;
    cout << "\n-Function For Floor-\n\n"
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
int myFloorFunction(float number)
{
    if (number >= 0)
        return int(number);
    else
    {
        if (int(number) == number)
            return int(number);
        else
            return int(number) - 1;
    }
}
void printResult(float numberFloor, float number)
{
    cout << "\n=============================\n"
         << "My Floor Result : " << numberFloor << '\n'
         << "C++ Floor Result: " << floor(number) << '\n';
}
int main()
{
    float number = readNumber();
    printResult(myFloorFunction(number), number);
    return 0;
}