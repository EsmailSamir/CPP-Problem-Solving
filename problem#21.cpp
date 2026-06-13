#include <iostream>
#include <cmath>
using namespace std;
void readCircumference(float &circumference)
{
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
}
float calculateCircleArea(const float circumference)
{
    const float PI = acos(-1);
    float circleArea = pow(circumference, 2) / (4 * PI);
    return circleArea;
}
void printCircleArea(const float circleArea)
{
    cout << "===========================\n"
         << "Circle Area = " << circleArea << '\n';
}
int main()
{
    float circumference;
    readCircumference(circumference);
    printCircleArea(calculateCircleArea(circumference));
    return 0;
}