#include <iostream>
#include <cmath>
using namespace std;
float readCircumference()
{
    float circumference;
    cout << "\nEnter Circumference: ";
    cin >> circumference;
    while (cin.fail() || circumference <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter Circumference: ";
        cin >> circumference;
    }
    return circumference;
}
float calculateCircleArea(const float &circumference)
{
    const float PI = acos(-1);
    float circleArea = circumference * circumference / (4 * PI);
    return circleArea;
}
void printCircleArea(const float &circleArea)
{
    cout << "===========================\n"
         << "Circle Area = " << circleArea << '\n';
}
int main()
{
    printCircleArea(calculateCircleArea(readCircumference()));
    return 0;
}